// Solve 2025-12-23

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

int n;
int half_n;
int x[100];
int y[100];
int mn = INF;

void check(int x1, int x2) {
    if (x1 > x2) swap(x1, x2);

    int dx = x2 - x1 + 2;
    vector<int> ys;

    for (int i = 0; i < n; i++) {
        if (x1 <= x[i] && x[i] <= x2) {
            ys.push_back(y[i]);
        }
    }

    sort(ys.begin(), ys.end());

    for (int i = 0, j = half_n - 1; j < size(ys); i++, j++) {
        int dy = ys[j] - ys[i] + 2;
        mn = min(mn, dx * dy);
    }
}

int main() {
    FASTIO;

    cin >> n;
    half_n = n / 2;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            check(x[i], x[j]);
        }
    }

    cout << mn << '\n';
    return 0;
}
