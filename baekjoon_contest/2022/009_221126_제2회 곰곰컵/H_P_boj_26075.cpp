// Solve 2022-11-26
// Update 2025-11-18

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
    string s, t;
    cin >> n >> m >> s >> t;
    int k = n + m;

    vector<int> v1, v2;

    for (int i = 0; i < k; i++) {
        if (s[i] == '1') {
            v1.push_back(i);
        }
    }

    for (int i = 0; i < k; i++) {
        if (t[i] == '1') {
            v2.push_back(i);
        }
    }

    ll cnt = 0;

    for (int i = 0; i < m; i++) {
        cnt += abs(v1[i] - v2[i]);
    }

    ll half = cnt / 2;

    if (cnt % 2 == 0) {
        cout << half * half * 2 << '\n';
    }
    else {
        cout << half * (half + 1) * 2 + 1 << '\n';
    }

    return 0;
}
