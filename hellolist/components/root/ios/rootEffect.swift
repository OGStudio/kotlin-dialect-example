import Foundation
import hl

func rootResetItems(_ vm: VM, _ items: KotlinArray<Item>) {
    var list = [Item]()
    let size = Int(items.size)
    if size > 0 {
        for i in 0..<size {
            if let ktItem = items.get(index: Int32(i)) {
                list.append(Item(id: Int(ktItem.id), title: ktItem.title))
            }
        }
    }
    vm.rootItems = list
}
