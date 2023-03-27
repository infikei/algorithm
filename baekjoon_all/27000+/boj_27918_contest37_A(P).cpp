// Solve 2023-03-26

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

    int n;
    cin >> n;

    int d = 0, p = 0;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == 'D') {
            d++;
        }
        else {
            p++;
        }

        if (abs(d - p) == 2) {
            for (int j = i + 1; j < n; j++) {
                cin >> x;
            }
            break;
        }
    }
    cout << d << ':' << p << '\n';

    return 0;
}
