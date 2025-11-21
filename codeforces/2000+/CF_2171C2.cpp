// Solve 2025-11-21

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

int a[200010];
int b[200010];

void solution() {
    int n;
    cin >> n;
    int x = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x ^= a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        x ^= b[i];
    }

    if (x == 0) {
        cout << "Tie" << '\n';
        return;
    }

    int mx_bit = 0;

    for (int i = 0; i < 20; i++) {
        if (x & (1 << i)) {
            mx_bit = i;
        }
    }

    int last = -1;

    for (int i = 0; i < n; i++) {
        if ((a[i] ^ b[i]) & (1 << mx_bit)) {
            last = i;
        }
    }

    cout << (last % 2 == 0 ? "Ajisai" : "Mai") << '\n';
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        solution();
    }

    return 0;
}
