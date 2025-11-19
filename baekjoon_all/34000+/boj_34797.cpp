// Solve 2025-11-19

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

    int n;
    cin >> n;

    int g_cnt[5] = {0};
    int bonus_cnt = 0;

    for (int i = 0; i < n; i++) {
        char g, t;
        cin >> g >> t;

        g_cnt[g - 'A']++;

        if (g <= 'C' && t == '1') {
            bonus_cnt += 2;
        }
        else if (g <= 'C' && t == '2') {
            bonus_cnt++;
        }
    }

    int g_sum = 0;

    for (int i = 0; i < 5; i++) {
        g_sum += (4 - i) * g_cnt[i];
    }

    double bonus = bonus_cnt * 0.025;
    double weighted_gpa = g_sum / (double) n + bonus;
    SETP(9);
    cout << weighted_gpa << '\n';
    return 0;
}
