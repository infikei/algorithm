// Solve 2023-06-01

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    while (true) {
        int b, n;
        cin >> b >> n;
        if (b == 0 && n == 0) break;

        int a = 1, a_n = 1;
        for (int k = 1; k <= b; k++) {
            int k_n = k;
            for (int i = 1; i < n; i++) {
                k_n *= k;
            }

            if (abs(b - a_n) > abs(b - k_n)) {
                a = k;
                a_n = k_n;
            }
            else if (abs(b - a_n) < abs(b - k_n)) {
                break;
            }
        }
        cout << a << '\n';
    }

    return 0;
}
