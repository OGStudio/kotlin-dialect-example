import SwiftUI

struct MainView: View {
    @ObservedObject var vm: VM

    init(_ vm: VM) {
        self.vm = vm
    }

    var body: some View {
        if vm.isVisible {
            VStack(spacing: 10) {
                Spacer()
                Text(vm.greetingText)
                Button(action: { mainSet(F.didClickChangeText, true) }) {
                    Text("Change text")
                }
                    .buttonStyle(.borderedProminent)
                Spacer()
            }
        }
    }
}
