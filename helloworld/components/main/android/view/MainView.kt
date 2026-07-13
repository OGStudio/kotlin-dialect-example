package org.opengamestudio

import androidx.compose.animation.*
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.Composable
import androidx.compose.ui.*
import androidx.compose.ui.platform.testTag
import androidx.compose.ui.unit.dp

@Composable
fun MainView(vm: VM) {
    AnimatedVisibility(
        enter = fadeIn(),
        exit = fadeOut(),
        modifier = Modifier,
        visible = vm.mainIsVisible.value,
    ) {
        Box(
            contentAlignment = Alignment.Center,
            modifier = Modifier.fillMaxSize()
        ) {
            Column(horizontalAlignment = Alignment.CenterHorizontally) {
                Text(vm.mainGreetingText.value, modifier = Modifier.testTag("greeting_text"))
                Spacer(modifier = Modifier.height(10.dp))
                OutlinedButton(
                    onClick = { mainSet(F.didClickChangeText, true) },
                ) {
                    Text("Change text", modifier = Modifier.testTag("change_text_button"))
                }
            }
        }
    }
}
