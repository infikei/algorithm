// Solve 2023-06-04

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using ld = long double;

const ld MAX_ERR = 1e-16;
ld a, b, c;

ld f(ld x) {
    return a * x + b * sin(x) - c;
}

int main() {
    FASTIO;

    cin >> a >> b >> c;

    ld low = (c - b) / a, high = (c + b) / a;
    int iter_cnt = 0, max_iter = 80;
    while (true) {
        ld mid = (low + high) * 0.5;
        ld fmid = f(mid);

        if (high - mid < MAX_ERR) {
            high = mid;
            break;
        }

        if (fmid < 0) {
            low = mid;
        }
        else if (fmid > 0) {
            high = mid;
        }
        else {
            high = mid;
            break;
        }

        iter_cnt++;
        if (iter_cnt >= max_iter) {
            break;
        }
    }

    SETPRECISION(16);
    cout << high << '\n';

    return 0;
}
