package org.opengamestudio

import androidx.compose.animation.*
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.Composable
import androidx.compose.ui.*
import androidx.compose.ui.unit.dp

@Composable
fun RootView(vm: VM) {
    AnimatedVisibility(
        enter = fadeIn(),
        exit = fadeOut(),
        modifier = Modifier,
        visible = vm.rootIsVisible.value,
    ) {
        Box(
            contentAlignment = Alignment.Center,
            modifier = Modifier.fillMaxSize()
        ) {
            Column(horizontalAlignment = Alignment.CenterHorizontally) {
                Text("TODO list")
                Spacer(modifier = Modifier.height(10.dp))
                OutlinedButton(
                    onClick = { rootSet(F.didClickAddItem, true) },
                ) {
                    Text("TODO Add item")
                }
            }
        }
    }
}
