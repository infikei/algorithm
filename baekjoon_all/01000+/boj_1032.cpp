// Solve 2022-06-06
// Update 2023-10-14

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

    string s[50];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    string ans;

    for (int j = 0, je = SIZE(s[0]); j < je; j++) {
        char ch = s[0][j];

        for (int i = 1; i < n; i++) {
            if (s[i][j] != ch) {
                ch = '?';
                break;
            }
        }

        ans.push_back(ch);
    }

    cout << ans << '\n';

    return 0;
}
