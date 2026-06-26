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

KTRef(Item) Items::rawItemAt(int id) const {
    auto raw = KT.arrElement(kref, id);
    return KT.anyAsItem(raw);
}

int Items::size() const {
    return KT.arrSize(kref);
}

Items RootContext_items(KTRef(RootContext) kref) {
    return Items(KT.RootContext.get_items(kref));
}

