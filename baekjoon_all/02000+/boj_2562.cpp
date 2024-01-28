// Solve 2022-06-03
// Update 2024-01-28

#include <iostream>
using namespace std;

int main() {
    int max_num = 0;
    int max_idx = 0;

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
