// Solve 2026-01-29

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

int cnt[4];

int main() {
    FASTIO;

    int n;
    cin >> n;
    int n3 = n * 3;

    for (int i = 0; i < n3; i++) {
        int v;
        cin >> v;

        cnt[v]++;
    }

    for (int v = 1; v <= 3; v++) {
        if (cnt[v] < n) {
            cout << v << '\n';
        }
    }

    for (int v = 1; v <= 3; v++) {
        if (cnt[v] > n) {
            cout << v << '\n';
        }
    }

    return 0;
}
