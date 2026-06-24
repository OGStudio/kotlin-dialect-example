#include "KT.h"

int Item::id() const {
    return KT.Item.get_id(raw);
}

QString Item::title() const {
    const char *s = KT.Item.get_title(raw);
    QString str(s);
    KTSym->DisposeString(s);
    return str;
}

Item Items::operator[](int id) const {
    auto raw = KT.arrElement(kref, id);
    return Item(KT.anyAsItem(raw));
}

int Items::size() const {
    return KT.arrSize(kref);
}

Items RootContext_items(KTRef(RootContext) kref) {
    return Items(KT.RootContext.get_items(kref));
}

