#include "KT.h"
#include "VM.h"

VM::VM() : QObject() {
    _rootIsVisible = false;
}

VM::~VM() {
    qDeleteAll(_rootItems);
}

bool VM::rootIsVisible() const {
    return _rootIsVisible;
}

QQmlListProperty<Item> VM::rootItems() const {
    return QQmlListProperty<Item>(
        const_cast<VM*>(this),
        nullptr,
        &VM::rootItemsCount,
        &VM::rootItemsAt
    );
}

Item *VM::rootItemsAt(
    QQmlListProperty<Item> *list,
    qsizetype index
) {
    auto *vm = qobject_cast<VM*>(list->object);
    return vm ? vm->_rootItems.at(index) : nullptr;
}

qsizetype VM::rootItemsCount(QQmlListProperty<Item> *list) {
    auto *vm = qobject_cast<VM*>(list->object);
    return vm ? vm->_rootItems.size() : 0;
}

void VM::rootSetIsVisible(bool value) {
    _rootIsVisible = value;
    emit rootDidChangeIsVisible(value);
}

void VM::rootSetItems(QList<Item*> items) {
    for (auto *item : _rootItems) {
        item->deleteLater();
    }
    _rootItems = items;
    emit rootDidChangeItems();
}
