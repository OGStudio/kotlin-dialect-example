package org.opengamestudio

import android.content.Context
import androidx.compose.runtime.*

object VM {
    var androidContext: Context? = null

    var mainGreetingText = mutableStateOf("TODO-Text")
    var mainIsVisible = mutableStateOf(false)
}
