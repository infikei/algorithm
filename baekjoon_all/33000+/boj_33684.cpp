// Solve 2025-04-25

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

int sauce[100000];

ll get_max_cnt(int n, int k) {
    sort(sauce, sauce + n);

    if (sauce[n - 1] > k) return 0;

    if (sauce[0] <= 0) return -1;

    ll cnt = 0;

    for (int i = 1; i < n; i++) {
        cnt += (k - sauce[i]) / sauce[0];
    }

    return cnt + 1;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> sauce[i];
    }

    cout << get_max_cnt(n, k) << '\n';

    return 0;
}
