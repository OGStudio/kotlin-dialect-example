import Foundation

func rootResetItems(_ vm: VM, _ items: [Any]) {
    vm.rootItems = items.map { item in
        let ktItem = item as! KotlinRootItem
        return Item(id: Int(ktItem.id), title: ktItem.title)
    }
}
