// Solve 2024-04-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int cnt[50];

int main() {
    FASTIO;

    int n, m, l;
    cin >> n >> m >> l;

    int i = 0;
    int ans = 0;

    while (true) {
        ans++;

        if (++cnt[i] >= m) {
            break;
        }

        if (cnt[i] % 2 == 0) {
            i = (i - l + n) % n;
        }
        else {
            i = (i + l) % n;
        }
    }

    cout << ans - 1 << '\n';

    return 0;
}
