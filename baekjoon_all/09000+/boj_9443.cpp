// Solve 2023-12-14

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

    bool check[26] = { false };

    for (int i = 0; i < n; i++) {
        string title;
        cin >> title;

        check[title[0] - 'A'] = true;
    }

    int ans = 0;

    for (int i = 0; i < 26; i++) {
        if (check[i]) {
            ans++;
        }
        else {
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
