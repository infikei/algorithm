// Solve 2024-04-28
// Update 2025-03-04

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int cnt[50];

int main() {
    FASTIO;

    int n, m, l;
    cin >> n >> m >> l;

    int cnt_throw = 0;
    int cur = 0;

    while (true) {
        if (++cnt[cur] >= m) {
            break;
        }

        cnt_throw++;

        if (cnt[cur] % 2 == 1) {
            cur = (cur + l) % n;
        }
        else {
            cur = (cur - l + n) % n;
        }
    }

    cout << cnt_throw << '\n';

    return 0;
}
