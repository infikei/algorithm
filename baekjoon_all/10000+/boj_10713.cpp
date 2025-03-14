// Solve 2025-03-14

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

int arr[100001];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int cur_city;
    cin >> cur_city;

    for (int i = 1; i < m; i++) {
        int nxt_city;
        cin >> nxt_city;

        arr[min(cur_city, nxt_city)]++;
        arr[max(cur_city, nxt_city)]--;

        cur_city = nxt_city;
    }

    // imos algorithm
    for (int i = 2; i <= n; i++) {
        arr[i] += arr[i - 1];
    }

    ll min_cost_sum = 0;

    for (int i = 1; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        min_cost_sum += min(a * arr[i], b * arr[i] + c);
    }

    cout << min_cost_sum << '\n';

    return 0;
}
