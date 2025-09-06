// Solve 2023-08-13
// Update 2025-09-05

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

bool state[2][7];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        memset(state, false, sizeof state);
        state[0][1] = true;

        for (int ni = 0; ni < n; ni++) {
            char op1, op2;
            int v1, v2;
            cin >> op1 >> v1 >> op2 >> v2;

            for (int d = 0; d < 7; d++) {
                if (!state[0][d]) continue;

                int d1 = (op1 == '+' ? d + v1 : d * v1) % 7;
                state[1][d1] = true;
                int d2 = (op2 == '+' ? d + v2 : d * v2) % 7;
                state[1][d2] = true;
            }

            swap(state[0], state[1]);
            memset(state[1], false, sizeof state[1]);
        }

        cout << (state[0][0] ? "LUCKY" : "UNLUCKY") << '\n';
    }

    return 0;
}
