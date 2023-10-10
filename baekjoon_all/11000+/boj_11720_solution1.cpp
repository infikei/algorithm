// Solve 2022-06-05
// Update 2023-10-10

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;

        ans += ch - '0';
    }

    cout << ans << '\n';

    return 0;
}
