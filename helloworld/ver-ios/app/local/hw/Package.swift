// swift-tools-version: 5.9

import PackageDescription

let package = Package(
  name: "hw",
  products: [
    .library(
      name: "hw",
      targets: ["hw"]
    ),
  ],
  targets: [    
    .binaryTarget(name: "hw", path: "hw.xcframework.zip")
  ]
)
