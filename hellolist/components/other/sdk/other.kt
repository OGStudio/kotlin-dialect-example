package org.opengamestudio

// TODO Generate
fun anyAsItem(item: Any?) = item as Item
// TODO Generate
fun arrElement(a: Array<Any?>, id: Int) = a.get(id)
// TODO Generate
fun arrSize(a: Array<Any?>) = a.size

// Print each key/value processed by a component into console
fun setupComponentDebugging(
    ctrl: KDController,
    prefix: String
) {
    ctrl.registerCallback { c ->
        val value = "${c.field<String>(c.recentField)}"
        println("ИГР $prefix k/v: '${c.recentField}'/'$value'")
    }
}
