#include "ignore.kd.h"
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

