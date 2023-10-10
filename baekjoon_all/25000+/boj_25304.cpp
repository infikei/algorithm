// Solve 2022-08-13
// Update 2023-10-10

#include <iostream>
using namespace std;

int main() {
    int amount, n;
    cin >> amount >> n;

    int calculated_amount = 0;

    for (int i = 0; i < n; i++) {
        int item_price, item_cnt;
        cin >> item_price >> item_cnt;

        calculated_amount += item_price * item_cnt;
    }

    if (amount == calculated_amount) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    return 0;
}
