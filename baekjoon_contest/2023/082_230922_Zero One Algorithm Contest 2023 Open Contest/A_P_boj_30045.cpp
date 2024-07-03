// Solve 2023-09-22
// Update 2023-12-25

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

    int ans = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        bool flag = false;

        for (int i = 1, ie = SIZE(s); i < ie; i++) {
            if (s[i - 1] == '0' && s[i] == '1') {
                flag = true;
                break;
            }

            if (s[i - 1] == 'O' && s[i] == 'I') {
                flag = true;
                break;
            }
        }

        if (flag) ans++;
    }

    cout << ans << '\n';

    return 0;
}
