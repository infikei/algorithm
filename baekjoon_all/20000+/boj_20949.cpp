// Solve 2026-01-19

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

    int n;
    cin >> n;
    vector<pair<int, int>> vec;

    for (int i = 1; i <= n; i++) {
        int w, h;
        cin >> w >> h;

        int ppi = w * w + h * h;
        vec.emplace_back(ppi, i);
    }

    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    };

    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << vec[i].second << '\n';
    }

    return 0;
}
