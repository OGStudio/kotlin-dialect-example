#ifndef HL_KT_H
#define HL_KT_H

#include "libhl_api.h"
#define KT libhl_symbols()->kotlin.root.org.opengamestudio
#define KTLibRef(NAME) libhl_kref_kotlin_##NAME
#define KTRef(NAME) libhl_kref_org_opengamestudio_##NAME
#define KTSym libhl_symbols()

#include <QString>
#include <vector>

class Item {
    public:
        Item(KTRef(Item) raw): raw(raw) { }

        int id() const;
        QString title() const;

    private:
        KTRef(Item) raw;
};

class Items {
    public:
        Items(KTLibRef(Array) kref): kref(kref) { }

        Item operator[](int id) const;
        int size() const;

    private:
        KTLibRef(Array) kref;
};

Items RootContext_items(KTRef(RootContext) kref);

#endif // HL_KT_H
