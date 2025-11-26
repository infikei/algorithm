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
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int n, k, l;
    cin >> n >> k >> l;

    vector<int> ratings;

    while (n-- > 0) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a < l || b < l || c < l || a + b + c < k) continue;

        ratings.push_back(a);
        ratings.push_back(b);
        ratings.push_back(c);
    }

    cout << size(ratings) / 3 << '\n';

    for (int& r : ratings) {
        cout << r << ' ';
    }

    cout << '\n';
    return 0;
}
