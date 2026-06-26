#include "KT.h"

Item::Item(KTRef(Item) raw, QObject *parent)
    : QObject(parent), raw(raw) { }

int Item::id() const {
    return KT.Item.get_id(raw);
}

QString Item::title() const {
    const char *s = KT.Item.get_title(raw);
    QString str(s);
    KTSym->DisposeString(s);
    return str;
}

Items::Items(KTLibRef(Array) kref) {
    int n = KT.arrSize(kref);
    for (int i = 0; i < n; ++i) {
        append(new Item(KT.anyAsItem(KT.arrElement(kref, i))));
    }
}

Items RootContext_items(KTRef(RootContext) kref) {
    return Items(KT.RootContext.get_items(kref));
}

