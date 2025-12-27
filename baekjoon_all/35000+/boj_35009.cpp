// Solve 2025-12-26

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

ll x[4];
ll y[4];
double len[6];

double get_dist(int i, int j) {
    ll dx = x[i] - x[j];
    ll dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
}

int main() {
    FASTIO;

    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0, u = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            len[u] = get_dist(i, j);
            u++;
        }
    }

    sort(len, len + 6);
    double area = M_PI * len[0] * len[2] * 0.25;
    SETP(12);
    cout << area << '\n';
    return 0;
}
