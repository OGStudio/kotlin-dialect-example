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

