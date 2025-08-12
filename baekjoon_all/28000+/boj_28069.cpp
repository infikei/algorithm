// Solve 2025-08-10

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

bool can_eat_minigimbob(int n, int k) {
    for (int i = 0; i < k; i++) {
        if (n % 3 == 2 || n == 1) {
            n--;
        }
        else if (n % 3 == 1) {
            n = (n - 1) / 3 * 2 + 1;
        }
        else {
            n = n / 3 * 2;
        }
    }

    return n == 0;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;
    cout << (can_eat_minigimbob(n, k) ? "minigimbob" : "water") << '\n';
    return 0;
}
