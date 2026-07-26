package org.opengamestudio

import androidx.compose.animation.*
import androidx.compose.foundation.background
import androidx.compose.foundation.lazy.*
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.Composable
import androidx.compose.ui.*
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.*

@Composable
fun RootView(
    modifier: Modifier,
    vm: VM
) {
    AnimatedVisibility(
        enter = fadeIn(),
        exit = fadeOut(),
        modifier = modifier,
        visible = vm.rootIsVisible.value,
    ) {
        Box(
            contentAlignment = Alignment.TopCenter,
            modifier = Modifier
                .fillMaxSize()
                .background(Color(0xFFFAFAFA))
        ) {
            Column(horizontalAlignment = Alignment.CenterHorizontally) {
                Text("TODO list")
                Spacer(modifier = Modifier.height(10.dp))
                OutlinedButton(
                    onClick = { rootSet(F.didClickAddItem, true) },
                ) {
                    Text("Add item")
                }
                Spacer(modifier = Modifier.height(10.dp))
                LazyColumn(
                    verticalArrangement = Arrangement.spacedBy(8.dp),
                    modifier = Modifier.padding(horizontal = 16.dp)
                ) {
                    items(vm.rootItems) { item ->
                        Box(modifier = Modifier.padding(vertical = 4.dp)) {
                            RootViewItem(item)
                        }
                    }
                }
            }
        }
    }
}
