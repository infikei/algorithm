// Solve 2025-08-29

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

int solution(int t, int bd) {
    int b = 0, d = 0;
    int loop = 2;
    int res = 0;

    while (true) {
        if (t == ++b && bd == 0) {
            return res;
        }

        res++;

        if (t == ++d && bd == 1) {
            return res;
        }

        res++;

        if (t == ++b && bd == 0) {
            return res;
        }

        res++;

        if (t == ++d && bd == 1) {
            return res;
        }

        res++;

        for (int i = 0; i < loop; i++) {
            if (t == ++b && bd == 0) {
                return res;
            }

            res++;
        }

        for (int i = 0; i < loop; i++) {
            if (t == ++d && bd == 1) {
                return res;
            }

            res++;
        }

        loop++;
    }
}

int main() {
    FASTIO;

    int a, t, bd;
    cin >> a >> t >> bd;

    cout << solution(t, bd) % a << '\n';
    return 0;
}
