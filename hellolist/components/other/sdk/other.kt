package org.opengamestudio

// TODO Generate for Item
fun anyAsItem(item: Any?) = item as Item

// Debug representation of a value
fun debugString(v: Any): String {
    // Prepend a string with its length
    if (v is String) {
        return "S(${v.length})$v"
    }

    // Prepend an array with its size
    if (v is Array<*>) {
        var out = ""
        for (item in v) {
            if (!out.isEmpty()) {
                out += ","
            }
            out += debugString(item!!)
        }
        return "A(${v.size})$out"
    }

    // Prepend a dictionary with its size
    if (v is Map<*, *>) {
        var out = ""
        for ((key, value) in v) {
            if (!out.isEmpty()) {
                out += ","
            }
            out += debugString(key!!) + ":" + debugString(value!!)
        }
        return "D(${v.size})$out"
    }

    // Otherwise just print by default
    return "$v"
}

// Print each key/value processed by a component into console
fun setupComponentDebugging(
    ctrl: KDController,
    prefix: String
) {
    ctrl.registerCallback { c ->
        //val value = c.field<String>(c.recentField)
        //val strval = debugString(value)
        //val strval = "${value}"
        val strval = "TODO"
        println("ИГР $prefix k/v: '${c.recentField}'/'$strval'")
    }
}
