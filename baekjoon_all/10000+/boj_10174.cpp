// Solve 2023-01-08
// Update 2023-12-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;
    cin.ignore();

    for (int k = 0; k < n; k++) {
        string s;
        getline(cin, s);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        bool ans = true;

        for (int i = 0, ie = SIZE(s) / 2; i < ie; i++) {
            char c = s[i];
            char c2 = s[SIZE(s) - 1 - i];

            if (c != c2) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "Yes" : "No") << '\n';
    }

    return 0;
}
