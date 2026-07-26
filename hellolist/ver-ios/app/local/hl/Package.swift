// swift-tools-version: 5.9

import PackageDescription

let package = Package(
  name: "hl",
  products: [
    .library(
      name: "hl",
      targets: ["hl"]
    ),
  ],
  targets: [    
    .binaryTarget(name: "hl", path: "hl.xcframework.zip")
  ]
)
