package org.opengamestudio

// Launch only once
//
// Purpose: Work around Android's activity restart
//
// Conditions:
// 1. UI has been created the first time
fun rootShouldLaunch(c: RootContext): RootContext {
    /* 1 */ if (
        c.recentField == F.didSetup &&
        !c.didLaunch
    ) {
        c.didLaunch = true
        c.recentField = F.didLaunch
        return c
    }

    c.recentField = F.none
    return c
}

// Reset items
//
// Conditions:
// 1. User did click `Add item` button
fun rootShouldResetItems(c: RootContext): RootContext {
    /* 1 */ if (c.recentField == F.didClickAddItem) {
        val item = Item()
        item.id = c.items.size
        item.name = "Item-${item.id}"
        c.items += item
        c.recentField = F.items
        return c
    }

    c.recentField = F.none
    return c
}

// Set main window visible
//
// Conditions:
// 1. Did launch
fun rootShouldResetVisibility(c: RootContext): RootContext {
    /* 1 */ if (c.recentField == F.didLaunch) {
        c.isVisible = true
        c.recentField = F.isVisible
        return c
    }

    c.recentField = F.none
    return c
}
