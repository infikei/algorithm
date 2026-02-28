// Solve 2026-02-26

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

int digit[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int a = 0; a <= 99; a++) {
        int a_digits = digit[a / 10] + digit[a % 10];

        for (int b = 0; b <= 99; b++) {
            int ab = a + b;

            if (ab >= 100) continue;

            int b_digits = digit[b / 10] + digit[b % 10];
            int ab_digits = digit[ab / 10] + digit[ab % 10];

            if (a_digits + b_digits + ab_digits + 4 == n) {
                SETW(2, '0'); cout << a << '+';
                SETW(2, '0'); cout << b << '=';
                SETW(2, '0'); cout << ab << '\n';
                return 0;
            }
        }
    }

    cout << "impossible" << '\n';
    return 0;
}
