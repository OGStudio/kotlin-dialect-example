#ifndef HL_KT_H
#define HL_KT_H

#include "libhl_api.h"
#define KT libhl_symbols()->kotlin.root.org.opengamestudio
#define KTRef(NAME) libhl_kref_org_opengamestudio_##NAME
#define KTSym libhl_symbols()

#include <QString>
#include <vector>

class Item {
    public:
        Item(KTRef(Item) raw): raw(raw) { }

        int id();
        QString title() const;

    private:
        KTRef(Item) raw;
};

class Items {
    public:
        Items(KTRef(RootContext) kref): kref(kref) { }

        Item operator[](int id);
        int size();

    private:
        KTRef(RootContext) kref;
};

Items RootContext_items(KTRef(RootContext) kref);

#endif // HL_KT_H
