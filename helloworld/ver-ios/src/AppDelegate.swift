import UIKit

class AppDelegate: UIResponder, UIApplicationDelegate {
    let mainCmp = MainComponent()
    let vm = VM()

    func application(
        _: UIApplication,
        didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]? = nil
    ) -> Bool {
        mainCmp.setup()

        return true
    }
}
