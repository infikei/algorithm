// Solve 2026-08-10

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

    int a, b;
    bool dan = false;
    
    while (cin >> a >> b) {
        if (a < 2 || a > 9 || b < 2 || b > 9) {
            cout << "INPUT ERROR!" << '\n';
            dan = false;
            continue;
        }

        if (a <= b) {
            for (int i = a; i <= b; i++) {
                if (dan) cout << '\n';

                for (int j = 1; j <= 9; j++) {
                    cout << i << " * " << j << " = " << i * j << '\n';
                }

                dan = true;
            }
        }
        else {
            for (int i = a; i >= b; i--) {
                if (dan) cout << '\n';

                for (int j = 1; j <= 9; j++) {
                    cout << i << " * " << j << " = " << i * j << '\n';
                }

                dan = true;
            }
        }
    }

    return 0;
}
