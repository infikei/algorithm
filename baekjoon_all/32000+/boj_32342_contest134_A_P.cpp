// Solve 2024-09-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int q;
    cin >> q;

    while (q-- > 0) {
        string s;
        cin >> s;

        int cnt = 0;

        for (int i = 2; i < s.size(); i++) {
            if (s.substr(i - 2, 3) == "WOW") {
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
