#include <cstdio>

#include "ignore.kd.h"
#include "rootEffect.h"

void rootResetItems(
    VM &vm,
    const Items &items
) {
    vm.rootSetItems(items);
}

