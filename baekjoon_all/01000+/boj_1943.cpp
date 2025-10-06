// Solve 2025-10-03
// Update 2025-10-05

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

bool memo[100001];

int main() {
    FASTIO;

    int t = 3;

    while (t-- > 0) {
        int n;
        cin >> n;
        map<int, int> coins;
        int amount_sum = 0;

        for (int i = 0; i < n; i++) {
            int v, x;
            cin >> v >> x;
            amount_sum += v * x;

            // 예를 들어, 10원 9개가 있으면, (10원, 20원, 40원, 나머지의 합)으로 분할
            int r = 1;

            while (true) {
                if (x < r) {
                    coins[v * x]++;
                    break;
                }

                coins[v * r]++;
                x -= r;
                r *= 2;
            }
        }

        // 총 금액의 합이 홀수라면 불가능
        if (amount_sum % 2 != 0) {
            cout << 0 << '\n';
            continue;
        }

        int amount_half = amount_sum / 2;
        memset(memo, false, sizeof memo);
        memo[0] = true;

        for (auto it = coins.begin(); it != coins.end(); it++) {
            int v = it->first;
            int x = it->second;

            while (x-- > 0) {
                for (int i = amount_half; i >= v; i--) {
                    if (memo[i - v]) {
                        memo[i] = true;
                    }
                }
            }
        }

        cout << memo[amount_half] << '\n';
    }

    return 0;
}
