#include <cstdio>

#include "ignore.kd.h"
#include "rootEffect.h"

void rootResetItems(const VM &vm) {
    printf("ИГР rootE.rootRE\n");
    auto rootCtx = KT.rootCtrlCtx();
    auto items = RootContext_items(rootCtx);
    for (int i = 0; i < items.size(); ++i) {
        printf("ИГР rootE.rootRE item id: '%d'\n", i);
    }
}

