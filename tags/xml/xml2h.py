import xmltodict
import sys
import xml.etree.ElementTree as ET


def printUsage():
    print("Usage: Python3 xml2h.py <xml file>")
    print("Converts the XML tag definition into a header for libInfinite")

if len(sys.argv) < 2:
    printUsage()
    sys.exit(0)

# if a struct name is used twice, add a struct for both uses. Otherwise, one will only be added for the first use
# If this option is enabled, the code will not compile, but it is useful to check if two structs really are the same or not
# different structs must have unique names in the XMLs
addDuplicateStructNames = False
addDuplicateEnumNames = False

# Type definitions
# https://github.com/Gamergotten/Infinite-runtime-tagviewer/blob/master/Halo/TagObjects/TagLayouts.cs

#################################################################################
#
# Certain fixed structs are defined in a separate header
# That header is included by all tagStruct headers
#
#################################################################################

preamble = '''#pragma once
#pragma pack(push,1)
#include \"../infiniteStructs.h\"\n#include <stdint.h>\n\n
/** 
  * This file was auto-generated with xml2h.py. DO NOT EDIT!!
  * Edit the XML files instead and regenerate this file.
  * Changes will not persist otherwise!
  */\n\n'''

endcode = '''#pragma pack(pop)
'''

class tagStructParser:

    anoncount = 0   # anonymous (unnamed) structs will be named sequentially

    # needed for format strings, they don't work otherwise
    sqOpen = '{'
    sqClose = '}'

    # string for one indentation
    indent = "    "

    outputCode = ""

    def __init__(self):
        self.outputCode = "// Structs\n\n"
        self.anoncount = 0
        self.flagDefinitions = "// Flag Definitions\n\n"
        self.enumDefinitions = "// Enum Definitions\n\n"
        self.typeMap = "// Tag Structure (used by the loader)\n\n"
        self.typeMapSize = 0
        # a map with all known struct types. elements are (use_count,[list representing the data types])
        self.knownStructs = {}
        self.knownEnums = []
        self.TypePrefix = ""


    def cleanNames(self, name : str):
        cleaned = name.replace(" ", "_").replace("/","_").replace("(","").replace(")","").replace("[","").replace("]","").replace(".","").replace("'","")
        cleaned = cleaned.replace("-","_")

        # also replace reserverd keywords
        if cleaned == "register":
            cleaned = "register_field"
        return cleaned


    # process an XML Entry. Returns the code to put at that place, 
    # either just for the field, or a pointer to a struct or other.
    # May create other structs in the process for nested structs
    # All nested structs will be completed before this function returns
    def handleEntry(self, eType, element, indentLevel,isArray = False, arrayCount = 0):

        indentString = "".join([self.indent for x in range(indentLevel)])

        self.typeMap += f"0x{eType[1:]},"
        self.typeMapSize += 1
        if eType == "_34":
            return self.parsePadding(element,indentLevel)
        
        if eType == "_3B":
            # this just marks the end of a struct, which isn't needed with the XMLs,
            # since their structure already does that
            return ""

        if eType == "_38":
            return self.parseStructDict(element, indentLevel,isArray=isArray, arrayCount=arrayCount)

        if eType == "_40":
            if isArray:
                print("#error CTBlock directly in an Array! This line should cause an error, as this isn't supported yet")
            return self.parseCTBlock(element,indentLevel)

        # most types are fields of some sort, so that will be handled by the parseField function
        # if it's an unknown type, that function adds in the error comment
        return self.parseField(eType,element,indentLevel,isArray,arrayCount)


    def parseFlags(self, eType, element, indentLevel):
        indentString = "".join([self.indent for x in range(indentLevel)])
        fieldName = self.cleanNames(element.attrib["v"])

        # add the flag definitions
        self.flagDefinitions += f"// Field {fieldName}\n\n"
        x = 0
        for flag in element:
            flagName = self.TypePrefix.upper() +  fieldName.upper() + "_" + self.cleanNames(flag.attrib["v"]).upper()
            self.flagDefinitions += f"#define {flagName} (1<<{str(x)})\n"
            x += 1
        self.flagDefinitions += "\n\n"


        if eType == "_F":
            return f"{indentString}uint8_t flags_{fieldName};\n"

        if eType == "_E":
            return f"{indentString}uint16_t flags_{fieldName};\n"

        if eType == "_D":
            return f"{indentString}uint32_t flags_{fieldName};\n"
        return ""

    def parseEnum(self, eType, element, indentLevel):
        indentString = "".join([self.indent for x in range(indentLevel)])
        fieldName = self.TypePrefix + self.cleanNames(element.attrib["v"])

        # add the enum definition
        if not fieldName in self.knownEnums or addDuplicateEnumNames:
            self.knownEnums.append(fieldName)
            self.enumDefinitions += f"// Enum {fieldName}\n\nenum {fieldName}_enum {self.sqOpen}\n"
            x = 0
            knownEnumFlags = {}
            for flag in element:
                flagName = self.cleanNames(f"{fieldName}_{flag.attrib['v']}").upper()
                if flagName in knownEnumFlags.keys():
                    knownEnumFlags[flagName] += 1
                    flagName = f"{flagName}_{knownEnumFlags[flagName] + 1}"
                else:
                    knownEnumFlags[flagName] = 0

                self.enumDefinitions += f"{self.indent}{flagName},\n"
                x += 1
            self.enumDefinitions = self.enumDefinitions[:-2]    # trim the last comma away
            self.enumDefinitions += "\n};\n\n"


        if eType == "_A":
            return f"{indentString}uint8_t enum_{fieldName};\n"

        if eType == "_B":
            return f"{indentString}uint16_t enum_{fieldName};\n"

        if eType == "_C":
            return f"{indentString}uint32_t enum_{fieldName};\n"
        return ""

    def parseArray(self,eType,element : ET.Element,indentLevel):
        count = 0
        if "count" in element.attrib.keys():
            # this makes stuff a bit easier, as the count is directly specified, which means I don't have to get it from the number of child elements
            count = int(element.attrib["count"])
        else:
            count = len(element) // 2
        self.typeMap += f"{count:#0{6}x},"
        self.typeMapSize += 2
        return f"// Array with {str(count)} elements\n" + self.handleEntry(element[0].tag, element[0],indentLevel,True,count)

    def parseField(self, eType, element, indentLevel, isArray = False, arrayCount = 0):
        indentString = "".join([self.indent for x in range(indentLevel)])
        fieldName = self.cleanNames(element.attrib["v"])
        arrayString = ""
        if isArray:
            arrayString = f"[{arrayCount}]"


        if eType == "_0":
            return f"{indentString}char {fieldName}[32];\n"

        if eType == "_1":
            return f"{indentString}char {fieldName}[256];\n"

        if eType == "_2":
            return f"{indentString}string_id {fieldName}{arrayString};\n"

        if eType == "_4":
            return f"{indentString}uint8_t {fieldName}{arrayString};\n"

        if eType == "_5":
            return f"{indentString}uint16_t {fieldName}{arrayString};\n"

        if eType == "_6":
            return f"{indentString}uint32_t {fieldName}{arrayString};\n"

        if eType == "_7":
            return f"{indentString}uint64_t {fieldName}{arrayString};\n"

        if eType == "_8":
            return f"{indentString}angle {fieldName}{arrayString};\n"

        if eType == "_D" or eType == "_E" or eType == "_F":
            return self.parseFlags(eType,element,indentLevel)

        if eType == "_A" or eType == "_B" or eType == "_C":
            return self.parseEnum(eType,element,indentLevel)

        if eType == "_14":
            return f"{indentString}float {fieldName}{arrayString};\n"

        if eType == "_15":
            return f"{indentString}float {fieldName}{arrayString};\n"

        if eType == "_16":
            return f"{indentString}struct point2D {fieldName}{arrayString};\n"

        if eType == "_17":
            return f"{indentString}struct point3D {fieldName}{arrayString};\n"

        if eType == "_18":
            return f"{indentString}struct vector2D {fieldName}{arrayString};\n"

        if eType == "_19":
            return f"{indentString}struct vector3D {fieldName}{arrayString};\n"

        if eType == "_1A":
            return f"{indentString}realQuaternion {fieldName}{arrayString};\n"

        if eType == "_1C":
            return f"{indentString}realEulerAngle3D {fieldName}{arrayString};\n"

        if eType == "_1D":
            return f"{indentString}realPlane2D {fieldName}{arrayString};\n"

        if eType == "_1E":
            return f"{indentString}realPlane3D {fieldName}{arrayString};\n"

        if eType == "_1F":
            return f"{indentString}realRGBColor {fieldName}{arrayString};\n"

        if eType == "_20":
            return f"{indentString}realARGBColor {fieldName}{arrayString};\n"

        if eType == "_25":
            return f"{indentString}realBounds {fieldName}{arrayString};\n"

        if eType == "_2E":
            return f"{indentString}shortBlockIndex {fieldName}{arrayString};\n"

        if eType == "_30":
            return f"{indentString}longBlockIndex {fieldName}{arrayString};\n"

        if eType == "_36":
            return f"{indentString}// EXPLANATION: {fieldName}{arrayString}\n"

        if eType == "_37":
            return f"{indentString}// CUSTOM: {fieldName}{arrayString}\n"

        if eType == "_39":
            return self.parseArray(eType,element,indentLevel)
            return f"{indentString}uint8_t {fieldName}[32];\n"

        if eType == "_3C":
            return f"{indentString}uint8_t {fieldName}{arrayString};\n"

        if eType == "_3D":
            return f"{indentString}uint16_t {fieldName}{arrayString};\n"

        if eType == "_3E":
            return f"{indentString}uint32_t {fieldName}{arrayString};\n"

        if eType == "_3F":
            return f"{indentString}uint64_t {fieldName}{arrayString};\n"

        if eType == "_41":
            return f"{indentString}struct tagReference {fieldName}{arrayString};\n"

        if eType == "_42":
            return f"{indentString}struct dataReference {fieldName}{arrayString};\n"

        if eType == "_43":
            if len(element) > 0:
                # child elements of the externalResource are described
                self.parseCTBlock(element,indentLevel)
                return f"{indentString}struct externalResource<{fieldName}> {fieldName}_res{arrayString};\n"
            else:
                # child elements aren't described, but the loader still needs to know that the description of the resource ends here
                # Content Table Entries will be skipped based on their hierarchy for this, so this is ok
                self.typeMap += "0x3B,"
                #pass
            return f"{indentString}struct externalResource<void> {fieldName}_res{arrayString};\n"

        if eType == "_44":
            return f"{indentString}uint32_t unknown_type_44_{fieldName}{arrayString};\n"

        return f"{indentString}//Unhandled type {eType}{arrayString}\n"


    def parsePadding(self, element, indentLevel):
        indentString = "".join([self.indent for x in range(indentLevel)])
        fieldName = self.cleanNames(element.attrib["v"])
        length = int(element.attrib["length"])

        # one entry in the typeMap string has already been made, but the C++ loader counts 0x34 as one byte padding, since also storing size is more complicated than just doing this
        if(length == 4):
            self.typeMap += f"0x34,0x34,0x34,"
            self.typeMapSize += 3
            return f"{indentString}uint32_t {fieldName};\n"
        if(length == 2):
            self.typeMap += f"0x34,"
            self.typeMapSize += 1
            return f"{indentString}uint16_t {fieldName};\n"
        if(length == 1):
            return f"{indentString}uint8_t {fieldName};\n"
        if(length == 3):
            self.typeMap += f"0x34,0x34,"
            self.typeMapSize += 2
            return f"{indentString}uint8_t {fieldName};\n{indentString}uint16_t {fieldName}_2;\n"
        if(length == 6):
            self.typeMap += f"0x34,0x34,0x34,0x34,0x34,"
            self.typeMapSize += 5
            return f"{indentString}uint32_t {fieldName};\n{indentString}uint16_t {fieldName}_2;\n"
        if(length == 7):
            self.typeMap += f"0x34,0x34,0x34,0x34,0x34,0x34,"
            self.typeMapSize += 6
            return f"{indentString}uint32_t {fieldName};\n{indentString}uint16_t {fieldName}_2;\n{indentString}uint8_t {fieldName}_3;\n"
        return f"{indentString}// WARNING: PADDING {str(length)} bytes\n"


    # field_block_v2
    # _40
    def parseCTBlock(self, structElement, indentLevel):
        # add the tagBlock struct to the file
        structCode = self.parseStructDict(structElement,0,addInline=False)
        indentString = "".join([self.indent for x in range(indentLevel)])
        self.outputCode += structCode + "\n\n"
        structname = self.cleanNames(structElement.attrib["v"])

        

        return f"{indentString}struct tagBlock<{structname}> {structname}_ent;\n"


    # struct
    # _38, also used by other types
    def parseStructDict(self, structElement, indentLevel, addInline = True, isArray = False, arrayCount = 0):
        indentString = "".join([self.indent for x in range(indentLevel)])

        arrayString = ""
        if isArray:
            arrayString = f"[{arrayCount}]"

        structname = self.cleanNames(structElement.attrib["v"])

        if structname == "":
            structname = f"anon_struct_{str(self.anoncount)}"
            self.anoncount += 1

        structname = self.TypePrefix + structname
        code = ""

        addStruct = True

        if structname in self.knownStructs.keys() and not addDuplicateStructNames:
            ## the same struct may be used in multiple places, so it has to be checked if it's the same or not
            # it is simply assumed that structs with the same name are the same (can be wrong though)

            #if len(structElement) != len(self.knownStructs[structname][1]):
            #    self.knownStructs[structname][0] += 1
            #    structname = f"{structname}_{self.knownStructs[structname][0]}"
            #else:
            #    isIndentical = True
            #    for idx, child in enumerate(structElement):
            #        if child.tag != self.knownStructs[structname][1][idx]:
            #            # the structs don't have the same data types
            #            isIndentical = False
            #            break
            #    
            #    if isIndentical:
            #        addStruct = False
            #    else:
            #        self.knownStructs[structname][0] += 1
            #        structname = f"{structname}_{self.knownStructs[structname][0]}"

            addStruct = False
        else:
            self.knownStructs[structname] = [0,[]]

        for child in structElement:
            code += self.handleEntry(child.tag,child,indentLevel + 1)
            #self.knownStructs[structname][1].append(child.tag)
            pass

        finalCode = f"{indentString}struct {structname}{self.sqOpen}\n{code}{indentString}{self.sqClose};\n"
        if not addStruct and not addInline:
            return ""
        if not addInline:
            return finalCode
            
        return finalCode + f"{indentString}struct {structname} {structname}_ent{arrayString};\n"


    def parseRoot(self, rootElement, rootName, srcPath = ""):
        rootName = self.cleanNames(rootName)
        code = f"struct {rootName}{self.sqOpen}\n"
        #self.TypePrefix = rootName + "_"
        self.typeMap += f"uint8_t {rootName}_structure[] {self.sqOpen}"
        for x in rootElement:
            #print(tagdict[x])
            code += self.handleEntry(x.tag,x, 1)
        code += "};\n"
        self.outputCode += "// Root Block\n\n"
        self.outputCode += code
        self.typeMap = self.typeMap[:-1]
        self.typeMap += "};\n\n"

        finalCode = preamble + f"// Generated from: {srcPath}\n\n" + self.flagDefinitions + "\n\n" + self.enumDefinitions + "\n\n" + self.outputCode + "\n\n"
        finalCode += f"#ifdef {rootName.upper()}_STRUCTURE_IMPL\n"
        finalCode += self.typeMap + "\n"
        finalCode += "#else\n"
        finalCode += f"extern uint8_t {rootName}_structure[{str(self.typeMapSize)}];\n"
        finalCode += "#endif\n\n\n"

        finalCode += endcode 
        print(finalCode)
        return finalCode

def main():

    root = ET.parse(sys.argv[1]).getroot()

    parser = tagStructParser()
    parser.parseRoot(root,sys.argv[1].replace("\\","/").split("/")[-1].split(".")[0],sys.argv[1])

    sys.exit(0)

if __name__ == "__main__":
    main()