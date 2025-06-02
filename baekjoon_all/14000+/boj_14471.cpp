// Solve 2025-06-01

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

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int sum_cnt = 0;
    int max_cnt = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int cur = max(n - a, 0);
        sum_cnt += cur;
        max_cnt = max(max_cnt, cur);
    }

    cout << sum_cnt - max_cnt << '\n';

    return 0;
}
