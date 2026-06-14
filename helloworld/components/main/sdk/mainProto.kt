package org.opengamestudio

object MainProto {
    val ctrl: KDController

    init {
        ctrl = KDController(MainContext())
        setupComponentDebugging(ctrl, "Main")
        arrayOf(
            ::mainShouldLaunch,
            ::mainShouldResetGreetingText,
            ::mainShouldResetVisibility,
        ).forEach { f ->
            ctrl.registerFunction { c -> f(c as MainContext) }
        }
    }
}

fun mainCtrl(): KDController {
    return MainProto.ctrl
}

fun mainCtrlCtx(): MainContext {
    return MainProto.ctrl.context as MainContext
}

fun mainCtrlCtxField(): String {
    return MainProto.ctrl.context.recentField
}

fun mainSet(k: String, v: Any) {
    MainProto.ctrl.set(k, v)
}
