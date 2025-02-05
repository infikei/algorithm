// Solve 2025-02-05

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        string s, t;
        cin >> s >> t;

        int zero_to_one = 0;
        int one_to_zero = 0;
        int unknown_to_zero = 0;
        int unknown_to_one = 0;

        for (int i = 0; i < size(s); i++) {
            if (s[i] == t[i]) continue;

            if (s[i] == '?') {
                if (t[i] == '0') {
                    unknown_to_zero++;
                }
                else {
                    unknown_to_one++;
                }
            }
            else if (s[i] == '0') {
                zero_to_one++;
            }
            else {
                one_to_zero++;
            }
        }

        int ans = 0;

        int tmp = min(zero_to_one, one_to_zero);
        zero_to_one -= tmp;
        one_to_zero -= tmp;
        ans += tmp;

        tmp = min(one_to_zero, unknown_to_one);
        one_to_zero -= tmp;
        unknown_to_one -= tmp;
        ans += tmp * 2;

        if (one_to_zero > 0) {
            cout << "Case " << ti << ": " << -1 << '\n';
            continue;
        }

        ans += zero_to_one + unknown_to_zero + unknown_to_one;
        cout << "Case " << ti << ": " << ans << '\n';
    }

    return 0;
}
