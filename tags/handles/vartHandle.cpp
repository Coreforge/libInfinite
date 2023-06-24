#include "vartHandle.h"
#include "../xml/generated/vart.h"

#include <cassert>


void vartHandle::setup(){
	vart* v = (vart*)root;
}

float vartHandle::getAspectRatio(){
	vart* v = (vart*)root;
	return v->aspectRatio;
}

uint32_t vartHandle::getDrawInfoCount(){
	vart* v = (vart*)root;
	return v->m_validDrawInformationCount;
}

vartHandle::drawInfo vartHandle::getDrawInfo(uint32_t index){
	vart* v = (vart*)root;
	assert(index < v->m_drawInformation_ent.count && "DrawInfo index out of bounds");

	vartHandle::drawInfo di;

	m_drawInformation* infoptr = &v->m_drawInformation_ent.block[index];
	di.indexCount = infoptr->index_count;
	di.indexStart = infoptr->index_start;
	di.vertexStart = infoptr->vertex_start;

	return di;
}

std::vector<vartHandle::vertex> vartHandle::getVertices(){
	vart* v = (vart*)root;

	std::vector<vartHandle::vertex> vect;
	vect.resize(v->m_vectorVertices_ent.count);

	// copy all the stuff over to the kinda standardised struct
	for(int i = 0; i < v->m_vectorVertices_ent.count; i++){
		m_vectorVertices* vert = &v->m_vectorVertices_ent.block[i];
		vect[i].region = vert->region_index;
		vect[i].render_type = vert->render_type;
		vect[i].x = vert->position.x;
		vect[i].y = vert->position.y;
	}

	return vect;
}

std::vector<uint16_t> vartHandle::getIndicies(){
	vart* v = (vart*)root;

	std::vector<uint16_t> vect;
	vect.resize(v->m_vectorIndices_ent.count);

	for(int i = 0; i < v->m_vectorIndices_ent.count; i++){
		vect[i] = v->m_vectorIndices_ent.block[i].index;
	}
	return vect;
}
