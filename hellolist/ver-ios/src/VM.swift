import Combine

class VM: ObservableObject {
    @Published var rootIsVisible = false
    @Published var rootItems: [Item] = []

    static private(set) weak var singleton: VM?

    init() {
        Self.singleton = self
    }
}

struct Item: Identifiable {
    let id: Int
    let title: String
}
