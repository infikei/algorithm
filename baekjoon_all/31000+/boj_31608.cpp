// Solve 2024-09-11

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s, t;
    cin >> n >> s >> t;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
