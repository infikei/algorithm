// Solve 2025-10-01

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

int tri[6];

bool solution() {
    for (int i = 0; i < 3; i++) {
        if (tri[i] != tri[i + 3]) {
            return false;
        }
    }

    return (tri[0] * tri[0] + tri[1] * tri[1] == tri[2] * tri[2]);
}

int main() {
    FASTIO;

    for (int i = 0; i < 6; i++) {
        cin >> tri[i];
    }

    sort(tri, tri + 3);
    sort(tri + 3, tri + 6);
    cout << (solution() ? "YES" : "NO") << '\n';

    return 0;
}
