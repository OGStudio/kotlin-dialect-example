plugins {
    alias(libs.plugins.kotlin.multiplatform)
}

kotlin {
    macosX64("native") {
        binaries {
            sharedLib {
                baseName = "hl"
            }
        }
    }
    sourceSets {
        nativeMain.dependencies {
        }
    }
}

tasks.withType<Wrapper> {
    distributionType = Wrapper.DistributionType.ALL
}
