#pragma once


// stuff to export functions
// basically copied from https://www.gnu.org/software/gnulib/manual/html_node/Exported-Symbols-of-Shared-Libraries.html
#define EXPORT_FUNC __attribute__((__visibility__("default")))
#if (defined _WIN32 && !defined __CYGWIN__)
#define EXPORT_FUNC __declspec(dllexport)
#endif
