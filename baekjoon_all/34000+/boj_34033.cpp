// Solve 2025-08-03

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

unordered_map<string, int> price_map;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    while (n-- > 0) {
        string name;
        int price;
        cin >> name >> price;
        price_map[name] = price;
    }

    int ans = 0;

    while (m-- > 0) {
        string name;
        int amount;
        cin >> name >> amount;

        if (amount > price_map[name] * 1.05) {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
