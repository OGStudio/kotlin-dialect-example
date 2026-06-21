#include "KT.h"
#include "VM.h"

VM::VM() : QObject() {
    _rootIsVisible = false;
}

bool VM::rootIsVisible() const {
    return _rootIsVisible;
}

void VM::rootSetIsVisible(bool value) {
    _rootIsVisible = value;
    emit rootDidChangeIsVisible(value);
}
