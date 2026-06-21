#include <any>
#include <cstdio>
#include <vector>

#include "root.h"
#include "ignore.kd.h"

#define CB(code) std::make_any<std::function<void(RootContext)>>([&](RootContext c) { code })
#define VM VM::singleton()


RootComponent::RootComponent() {
    std::vector<std::any> oneliners = {
        F.isVisible, CB( VM.rootSetIsVisible(c.isVisible()); ),
    };
    RootEffectRegistry::registerOneliners(KT.rootCtrl(), oneliners);
}

void RootComponent::setup() {
    rootSet(F.didSetup, true);
}
