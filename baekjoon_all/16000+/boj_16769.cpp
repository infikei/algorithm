// Solve 2026-02-15

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

ll c[3];
ll m[3];

void move(int i, int j) {
    ll x = min(m[i], c[j] - m[j]);
    m[i] -= x;
    m[j] += x;
}

// void test_print() {
//     for (int i = 0; i < 3; i++) {
//         cout << m[i] << ' ';
//     }
//     cout << '\n';
// }

int main() {
    FASTIO;

    for (int i = 0; i < 3; i++) {
        cin >> c[i] >> m[i];
    }

    for (int i = 0; i < 33; i++) {
        move(0, 1);
        move(1, 2);
        move(2, 0);
    }

    move(0, 1);

    for (int i = 0; i < 3; i++) {
        cout << m[i] << '\n';
    }

    return 0;
}
