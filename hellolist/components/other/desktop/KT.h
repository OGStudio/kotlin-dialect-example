#ifndef HL_KT_H
#define HL_KT_H

#include "libhl_api.h"
#define KT libhl_symbols()->kotlin.root.org.opengamestudio
#define KTLibRef(NAME) libhl_kref_kotlin_##NAME
#define KTRef(NAME) libhl_kref_org_opengamestudio_##NAME
#define KTSym libhl_symbols()

#endif // HL_KT_H
