package org.opengamestudio

import android.content.Context
import androidx.compose.runtime.*

object VM {
    var androidContext: Context? = null

    var rootIsVisible = mutableStateOf(false)
    var rootItems = mutableStateListOf<Item>()
}
