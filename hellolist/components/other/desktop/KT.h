#ifndef HL_KT_H
#define HL_KT_H

#include "libhl_api.h"
#define KT libhl_symbols()->kotlin.root.org.opengamestudio
#define KTRef(NAME) libhl_kref_org_opengamestudio_##NAME
#define KTSym libhl_symbols()

#include <QString>

class Item {
    public:
        Item(KTRef(Item) raw): raw(raw) { }

        int id();
        QString title() const;

    private:
        KTRef(Item) raw;
};

#endif // HL_KT_H
