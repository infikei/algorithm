// Solve 2025-11-24

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
using pdc = pair<double, char>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int x, n;
    cin >> x >> n;

    vector<pdc> votes;
    map<char, int> mp;

    for (int i = 0; i < n; i++) {
        char c;
        int v;
        cin >> c >> v;

        if (v * 20 < x) continue;

        for (int j = 1; j <= 14; j++) {
            votes.emplace_back(v / (double) j, c);
        }

        mp[c] = 0;
    }

    sort(votes.begin(), votes.end(), greater<>());

    for (int i = 0; i < 14; i++) {
        mp[votes[i].second]++;
    }

    for (auto [c, d] : mp) {
        cout << c << ' ' << d << '\n';
    }

    return 0;
}
