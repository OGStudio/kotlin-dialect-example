import hw

typealias MC = MainContext

class MainComponent {
    init() {
        var vm = { VM.singleton! }

        let effects: [Any] = [
            F.greetingText, { (c: MC) in vm().greetingText = c.greetingText },
            F.isVisible, { (c: MC) in vm().isVisible = c.isVisible },
        ]
        var r: MC? = registerOneliners(mainCtrl(), effects)
    }

    func setup() {
        mainSet(F.didSetup, true)
    }
}
