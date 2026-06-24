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
    return KT.arrElement(kref, id);
}

int Items::size() {
    return KT.arrSize(kref);
}

Items RootContext_items(KTRef(RootContext) kref) {
    //auto rootCtx = KT.rootCtrlCtx();
    auto kref = KT.RootContext.get_items(ctx);
    return Items(kref);
}

