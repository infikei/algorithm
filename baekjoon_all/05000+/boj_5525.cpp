// Solve 2023-08-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    string s;
    cin >> n >> m >> s;

    int cnt = 0;

    for (int i = 0; i < m; i++) {
        if (s[i] == 'O') continue;

        int now = 0;

        while (i + 2 < m && s[i + 1] == 'O' && s[i + 2] == 'I') {
            i += 2;
            now++;
        }

        cnt += max(0, now + 1 - n);
    }

    cout << cnt << '\n';

    return 0;
}
