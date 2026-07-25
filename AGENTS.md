# Kotlin Dialect Example Repository

Multiplatform example projects built with [Kotlin Dialect](https://github.com/OGStudio/kotlin-dialect) (KD) — a custom state-machine/reducer framework.

## Projects

| Project | Description | Targets |
|---------|-------------|---------|
| `helloworld/` | Minimal KD example (single greeting text) | Android, iOS, macOS, Linux, Windows |
| `hellolist/` | TODO list example with Item struct | Android, macOS |
| `sample_gb/` | Git Budget reference app (symlink) | Android, iOS, macOS |

## Architecture: Kotlin Dialect

- **Contexts** (`*Context` data classes in `ignore.kd.kt`) hold all app state
- **should-functions** (reducers in `*Should.kt`) check `c.recentField` against `F.*` constants, return mutated context
- **`F` object** (in `ignore.kd.kt`) contains string constants for all field names
- `KDController` manages the event queue: `set(fieldName, value)` → processes all registered functions → fires callbacks

## Component approach to file hierarchy

Source of truth lives in `components/` directory. Platform-specific directories symlink back to it.

### Component structure

Each component has platform subdirectories:

```
components/<name>/
├── sdk/           # Cross-platform Kotlin (reducers, proto, constants)
├── android/       # Android-specific (Compose UI, VM bindings, effects)
├── ios/           # iOS-specific (SwiftUI views, VM bindings, effects)
├── desktop/       # Desktop-specific (C++/Qt, QML views)
│   └── view/      # QML views
└── <platform>/view/  # Platform views go inside view/ subdir
```

### Symlink convention

All `ver-*` and `sdk-*` directories contain symlinks pointing back to `components/`:

- `ver-android/.../<component>/*.kt` → `components/<component>/{sdk,android}/*`
- `ver-ios/src/<component>/*.swift` → `components/<component>/ios/*`
- `ver-ios/src/<component>/view/*.swift` → `components/<component>/ios/view/*`
- `ver-mac-x64/src/<component>/*` → `components/<component>/desktop/*`
- `sdk-ios/hw/src/commonMain/.../*.kt` → `components/<component>/sdk/*`
- `sdk-ios/gradle*` → `../ver-android/gradle*` (shared Gradle wrapper)
- `ver-ios/app/local/<module>/xcframework.zip` → `sdk-ios/.../xcframework.zip` (built artifact)

**Edit files in `components/`** — editing symlink targets will appear to work but won't show in `git status` for the canonical path.

Files starting with `ignore` are not tracked in git. `ignore` files should not be edited because they come from `kd.yml` after generation.

## Conventions

- Package: `org.opengamestudio`
- Module names: `hw` (helloworld), `hl` (hellolist)
- KD branch: `cpparr`
- Kotlin: 2.2.0

## File naming

| Pattern | Location | Purpose |
|---------|----------|---------|
| `*Should.kt` | `components/*/sdk/` | Reducers |
| `*Proto.kt` | `components/*/sdk/` | Controller setup, exposes `ctrl()` and `set()` |
| `*Const.kt` | `components/*/sdk/` | Constants |
| `*Fun.kt` | `components/*/sdk/` | Utility functions |
| `other.kt` | `components/other/sdk/` | Shared utilities (`setupComponentDebugging`) |
| `*Effect.kt` | `components/*/android/` or `ios/` | Platform-specific effects |
| `*.swift` | `components/*/ios/` | iOS effects, component wiring |
| `view/*.swift` | `components/*/ios/view/` | SwiftUI views |
| `*.kt` | `components/*/android/` | Android effects, component wiring |
| `view/*.kt` | `components/*/android/view/` | Compose views |
| `ignore.kd.*` | Generated everywhere | **Do not edit** — generated from `kd.yml` |

## Code generation

`kd.yml` defines data structs and contexts. Regenerate after changes:

```
./util/build-ios          # Full iOS build (cloneKD + genKD + XCFramework + xcodegen)
./util/build-android      # Android (cloneKD + genKD only)
./util/build-mac-x64      # macOS desktop (cloneKD + genKD + SDK + CMake)
```

Or run KD generation standalone:
```
node $KD_DIR/dist/app.js --file=kd.yml
```

## Build pipelines

### iOS
1. `cloneKD` — clones kotlin-dialect repo (branch: `cpparr`)
2. `genKD` — generates all `ignore.kd.*` files from `kd.yml`
3. `buildIOSSDK` — builds XCFramework via Gradle, zips it, symlinks to `ver-ios/app/local/<module>/`
4. `genIOSProject` — runs `xcodegen` in `ver-ios/app/` to generate `.xcodeproj`

### Desktop
1. `cloneKD` → `genKD`
2. `buildDesktopSDK` — `./gradlew linkReleaseSharedNative` (produces lib<module>)
3. `buildDesktop` — CMake build (links against lib, produces Qt app)

### Android
1. `cloneKD` → `genKD`
2. Build via Android Studio or `./gradlew assembleDebug` in `ver-android/`

## iOS project structure

- `sdk-ios/` — KMP project producing XCFramework (iosArm64, iosSimulatorArm64, iosX64)
- `ver-ios/` — SwiftUI app
  - `app/project.yml` — XcodeGen spec
  - `app/local/<module>/Package.swift` — Swift Package wrapping xcframework
  - `src/ignore.kd.swift` — Generated Swift (F struct, KDController extensions)
  - `src/VM.swift` — ObservableObject for SwiftUI state
  - `src/AppDelegate.swift` — UIApplicationDelegate, creates components
  - `src/AppView.swift` — @main SwiftUI App
