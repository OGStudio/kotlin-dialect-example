package org.opengamestudio

object RootProto {
    val ctrl: KDController

    init {
        ctrl = KDController(RootContext())
        setupComponentDebugging(ctrl, "Root")
        arrayOf(
            ::rootShouldLaunch,
            ::rootShouldResetItems,
            ::rootShouldResetVisibility,
        ).forEach { f ->
            ctrl.registerFunction { c -> f(c as RootContext) }
        }
    }
}

fun rootCtrl(): KDController {
    return RootProto.ctrl
}

fun rootCtrlCtx(): RootContext {
    return RootProto.ctrl.context as RootContext
}

fun rootCtrlCtxField(): String {
    return RootProto.ctrl.context.recentField
}

fun rootSet(k: String, v: Any) {
    RootProto.ctrl.set(k, v)
}
