import UIKit

class AppDelegate: UIResponder, UIApplicationDelegate {
    let rootCmp = RootComponent()
    let vm = VM()

    func application(
        _: UIApplication,
        didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]? = nil
    ) -> Bool {
        rootCmp.setup()

        return true
    }
}
