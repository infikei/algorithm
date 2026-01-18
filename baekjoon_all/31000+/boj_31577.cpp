// Solve 2026-01-16

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

vector<int> computer[15];

int main() {
    FASTIO;

    int cur = 0;

    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j < 6; j++) {
            computer[cur].push_back(i);
            cur = (cur + 1) % 15;
        }
    }

    for (int i = 0; i < 15; i++) {
        for (int x : computer[i]) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}
