// Solve 2023-03-19
// Update 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

#ifdef BOJ
using Int = __int128;
using Float = __float128;
const Float PI = 3.14159265358979323846264338327950288419716939937510q;
const Float MAX_ERR = 0.000000000000000000000001q;
#else
using Int = long long;
using Float = long double;
const Float PI = 3.1415926535897932384626433832795028841971l;
const Float MAX_ERR = 0.000000000001l;
#endif

int a, b, c;

Float new_sin(Float x) {
    Float pi2 = PI * 2;
    x -= (Int)(x / pi2) * pi2;

    Float res = x;
    Float x2 = -x * x;
    Int i = 0;
    Float term = x;

    while (true) {
        i += 2;
        term *= x2 / (i * i + i);
        res += term;

        if (i >= 34) break;
    }

    return res;
}

Float f(Float x) {
    return a * x + b * new_sin(x) - c;
}

int main() {
    FASTIO;

    cin >> a >> b >> c;

    Float low = (c - b) / (Float)a, high = (c + b) / (Float)a;
    int iter_cnt = 0, max_iter = 120;

    while (true) {
        Float mid = (low + high) / 2;
        Float fmid = f(mid);

        if (high - low < MAX_ERR) {
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

        if (++iter_cnt >= max_iter) break;
    }

    SETPRECISION(6);

    cout << (long double)((Int)(high * 1000000 + 0.5) / (Float)1000000) << '\n';

    return 0;
}
