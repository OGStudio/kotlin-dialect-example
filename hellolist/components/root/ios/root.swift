import hl

typealias RC = RootContext

class RootComponent {
    init() {
        var vm = { VM.singleton! }

        let effects: [Any] = [
            F.isVisible, { (c: RC) in vm().rootIsVisible = c.isVisible },
            F.items, { (c: RC) in rootResetItems(vm(), c.items) },
        ]
        var r: RC? = registerOneliners(rootCtrl(), effects)
    }

    func setup() {
        rootSet(F.didSetup, true)
    }
}
