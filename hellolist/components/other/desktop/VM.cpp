#include "KT.h"
#include "VM.h"

VM::VM() : QObject() {
    _rootIsVisible = false;
}

bool VM::rootIsVisible() const {
    return _rootIsVisible;
}

QStringList VM::rootItems() const {
    return _rootItems;
}

void VM::rootSetIsVisible(bool value) {
    _rootIsVisible = value;
    emit rootDidChangeIsVisible(value);
}

void VM::rootSetItems(QStringList items) {
    _rootItems = items;
    emit rootDidChangeItems(items);
}
