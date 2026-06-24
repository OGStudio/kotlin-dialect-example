#include <any>
#include <cstdio>
#include <vector>

#include "ignore.kd.h"
#include "root.h"
#include "rootEffect.h"

#define CB(code) std::make_any<std::function<void(RootContext)>>([&](RootContext c) { code })
#define VM VM::singleton()

RootComponent::RootComponent() {
    std::vector<std::any> oneliners = {
        F.isVisible, CB( VM.rootSetIsVisible(c.isVisible()); ),
        F.items, CB( rootSetItems(VM/*, c.items()*/); ),
    };
    RootEffectRegistry::registerOneliners(KT.rootCtrl(), oneliners);
}

void RootComponent::setup() {
    rootSet(F.didSetup, true);
}
