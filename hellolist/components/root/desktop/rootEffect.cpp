#include <cstdio>

#include "ignore.kd.h"
#include "rootEffect.h"

void rootResetItems(
    VM &vm,
    const Items &items
) {
    QList<Item*> itemList;
    for (int i = 0; i < items.size(); ++i) {
        itemList.append(new Item(items.rawItemAt(i)));
    }
    vm.rootSetItems(itemList);
}

