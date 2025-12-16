// Solve 2025-12-13

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<pii> vec;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        vec.emplace_back(i, a);
    }

    int iter = n - m + 1;
    auto cmp = [](pii& a, pii& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    };

    while (iter-- > 0) {
        int v;
        cin >> v;
        sort(vec.begin(), vec.begin() + m, cmp);
        vec.erase(vec.begin() + (v - 1));
    }

    for (pii& p : vec) {
        cout << p.second << ' ';
    }

    cout << '\n';
    return 0;
}
