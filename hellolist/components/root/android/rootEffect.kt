package org.opengamestudio

fun rootResetItems(
    vm: VM,
    items: Array<Item>
) {
    vm.rootItems.clear()
    vm.rootItems.addAll(items)
}
