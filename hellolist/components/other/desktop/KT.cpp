#include "KT.h"

int Item::id() {
    return KT.Item.get_id(raw);
}

QString Item::title() const {
    const char *s = KT.Item.get_title(raw);
    QString str(s);
    KTSym->DisposeString(s);
    return str;
}

Item Items::operator[](int id) {
    auto raw = KT.arrElement(kref, id);
    return Item(KT.anyAsItem(raw));
}

int Items::size() {
    return KT.arrSize(kref);
}

Items RootContext_items(KTRef(RootContext) kref) {
    //auto rootCtx = KT.rootCtrlCtx();
    return Items(KT.RootContext.get_items(kref));
}

