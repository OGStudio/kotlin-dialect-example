#include <cstdio>

#include <QStringList>

#include "ignore.kd.h"
#include "rootEffect.h"

void rootResetItems(
    VM &vm,
    const Items &items
) {
    QStringList titles;
    for (int i = 0; i < items.size(); ++i) {
        auto item = items[i];
        titles.append(item.title());
    }
    vm.rootSetItems(titles);
}

