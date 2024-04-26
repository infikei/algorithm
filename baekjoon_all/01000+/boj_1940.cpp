// Solve 2024-04-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int cnt[100001];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cnt[x]++;
    }

    int ans = 0;

    if (m <= 200000) {
        int i = m / 2;
        int j = i + 1;

        if (m % 2 == 0) {
            ans += cnt[m / 2] / 2;
            i--;
        }

        while (i >= 0 && j <= m) {
            ans += min(cnt[i], cnt[j]);
            i--;
            j++;
        }
    }

    cout << ans << '\n';

    return 0;
}
