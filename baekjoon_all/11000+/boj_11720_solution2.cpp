// Solve 2022-06-05
// Update 2023-10-10

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += s[i] - '0';
    }

    cout << ans << '\n';

    return 0;
}
