// Solve 2025-05-25

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int a, b, c, s, v, l;
    cin >> a >> b >> c >> s >> v >> l;

    int t = 0;
    int exp = 0;

    while (v-- > 0) {
        int iter = 30;

        while (iter-- > 0) {
            t++;
            exp += c;

            if (exp >= 100) {
                exp -= 100;
                l++;

                if (l >= 250) {
                    cout << t << '\n';
                    return 0;
                }
            }
        }
    }

    while (s-- > 0) {
        int iter = 30;

        while (iter-- > 0) {
            t++;
            exp += b;

            if (exp >= 100) {
                exp -= 100;
                l++;

                if (l >= 250) {
                    cout << t << '\n';
                    return 0;
                }
            }
        }
    }

    while (true) {
        int iter = 30;

        while (iter-- > 0) {
            t++;
            exp += a;

            if (exp >= 100) {
                exp -= 100;
                l++;

                if (l >= 250) {
                    cout << t << '\n';
                    return 0;
                }
            }
        }
    }

    return 0;
}
