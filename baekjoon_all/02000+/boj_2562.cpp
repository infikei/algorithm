// Solve 2022-06-03
// Update 2023-10-10

#include <iostream>
using namespace std;

int main() {
    int max_num = 0, max_idx = 0;

    for (int i = 1; i <= 9; i++) {
        int num;
        cin >> num;

        if (num > max_num) {
            max_num = num;
            max_idx = i;
        }
    }

    cout << max_num << '\n';
    cout << max_idx << '\n';

    return 0;
}
