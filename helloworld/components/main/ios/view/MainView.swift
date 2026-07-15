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
                    .accessibilityIdentifier("greeting_text")
                Button(action: { mainSet(F.didClickChangeText, true) }) {
                    Text("Change text")
                }
                    .accessibilityIdentifier("change_text_button")
                    .buttonStyle(.borderedProminent)
                Spacer()
            }
        }
    }
}
