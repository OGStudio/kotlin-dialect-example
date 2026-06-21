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
