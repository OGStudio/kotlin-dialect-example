package org.opengamestudio

typealias RC = RootContext

object RootComponent {
    init {
        val vm = VM
        val oneliners = arrayOf(
            F.isVisible, { c: RC -> vm.rootIsVisible.value = c.isVisible },
            F.items, { c: RC -> rootResetItems(vm, c.items) },
        )
        registerOneliners(rootCtrl(), oneliners)
    }

    fun setup() {
        rootSet(F.didSetup, true)
    }
}
