#include <cstdio>

#include <QStringList>

#include "ignore.kd.h"
#include "rootEffect.h"

void rootResetItems(VM &vm) {
    printf("ИГР rootE.rootRE\n");
    auto rootCtx = KT.rootCtrlCtx();
    auto items = RootContext_items(rootCtx);
    QStringList titles;
    for (int i = 0; i < items.size(); ++i) {
        auto item = items[i];
        //printf("ИГР rootE.rootRE item id/title: '%d'/'%s'\n", item.id(), item.title().toStdString().c_str());
        titles.append(item.title());
    }
    vm.rootSetItems(titles);
}

