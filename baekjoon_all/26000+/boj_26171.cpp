// Solve 2023-08-22
// Update 2024-03-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n = 0;
    int ans = 0;
    string s;

    while (true) {
        cout << "? 1 " << ++n << endl;
        cin >> s;

        if (s == "ArrayIndexOutOfBoundsException") {
            n--;
            break;
        }

        ans = max(ans, stoi(s));
    }

    int v;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "? " << i << ' ' << j << endl;
            cin >> v;

            ans = max(ans, v);
        }
    }

    cout << "! " << ans << endl;

    return 0;
}
