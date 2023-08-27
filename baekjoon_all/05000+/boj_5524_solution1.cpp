// Solve 2022-10-25
// Update 2023-08-27

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

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int i = 0, ie = SIZE(s); i < ie; i++) {
            if (s[i] < 'a') {
                s[i] = s[i] - 'A' + 'a';
            }
        }

        cout << s << '\n';
    }

    return 0;
}
