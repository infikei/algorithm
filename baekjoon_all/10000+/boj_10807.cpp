// Solve 2022-06-20
// Update 2023-12-19

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[100];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int v;
    cin >> v;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == v) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
