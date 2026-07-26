import SwiftUI

struct RootViewItem: View {
    let item: Item

    var body: some View {
        HStack {
            Text(String(format: "%02d", item.id))
                .font(.caption)
                .foregroundColor(.gray)
                .frame(width: 28)
            Text(item.title)
                .font(.body)
        }
    }
}
