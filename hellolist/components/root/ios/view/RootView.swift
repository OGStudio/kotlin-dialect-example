import SwiftUI

struct RootView: View {
    @ObservedObject var vm: VM

    init(_ vm: VM) {
        self.vm = vm
    }

    var body: some View {
        if vm.rootIsVisible {
            NavigationView {
                VStack(spacing: 10) {
                    List {
                        ForEach(vm.rootItems) { item in
                            RootViewItem(item: item)
                        }
                    }
                    Button(action: { rootSet(F.didClickAddItem, true) }) {
                        Text("Add item")
                    }
                        .buttonStyle(.borderedProminent)
                        .padding()
                }
                    .navigationTitle("TODO list")
            }
        }
    }
}
