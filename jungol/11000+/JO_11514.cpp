// Solve 2026-06-20

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

    while (true) {
        string k;
        cin >> k;

        if (k[0] == '0') break;

        string p;
        cin >> p;

        for (int i = 0; i < size(p); i++) {
            p[i] = (p[i] - 'A' + k[i % size(k)] - 'A' + 1) % 26 + 'A';
        }

        cout << p << '\n';
    }

    return 0;
}
