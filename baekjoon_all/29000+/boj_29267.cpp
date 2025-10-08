// Solve 2025-10-08

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

    int n, k;
    cin >> n >> k;
    int saved = 0;
    int bullet = 0;

    while (n-- > 0) {
        string cmd;
        cin >> cmd;

        if (cmd == "save") {
            saved = bullet;
        }
        else if (cmd == "load") {
            bullet = saved;
        }
        else if (cmd == "shoot") {
            bullet--;
        }
        else if (cmd == "ammo") {
            bullet += k;
        }

        cout << bullet << '\n';
    }

    return 0;
}
