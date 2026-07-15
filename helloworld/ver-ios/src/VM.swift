import Combine

class VM: ObservableObject {
    @Published var greetingText = "TODO-Text"
    @Published var isVisible = false

    static private(set) weak var singleton: VM?

    init() {
        Self.singleton = self
    }
}
