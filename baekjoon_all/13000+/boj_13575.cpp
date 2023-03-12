// Solve 2023-03-12

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
using cpx = complex<double>;

const double PI = acos(-1);
const int FFT_SIZE = 1 << 20;

void fft(vector<cpx> &a, bool inv = false) {
    int n = SIZE(a);

    // bit reversal
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) {
            bit >>= 1;
        }
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    for (int k = 1; k < n; k <<= 1) {
        double theta = (inv ? -PI / k : PI / k);
        cpx w(cos(theta), sin(theta));

        int k2 = (k << 1);
        for (int i = 0; i < n; i += k2) {
            cpx wp(1, 0);
            for (int j = 0; j < k; j++) {
                cpx even = a[i + j], odd_wp = a[k + i + j] * wp;
                a[i + j] = even + odd_wp;
                a[k + i + j] = even - odd_wp;
                wp *= w;
            }
        }
    }

    if (inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}

vector<int> calc_vec_mul(const vector<int> &a, const vector<int> &b) {
    vector<cpx> a_cpx(ALL(a)), b_cpx(ALL(b));
    int sz = 1;
    while (sz < SIZE(a) + SIZE(b)) {
        sz <<= 1;
    }
    a_cpx.resize(sz); b_cpx.resize(sz);

    fft(a_cpx); fft(b_cpx);
    for (int i = 0; i < sz; i++) {
        a_cpx[i] *= b_cpx[i];
    }
    fft(a_cpx, true);

    vector<int> res(sz);
    for (int i = 0; i < sz; i++) {
        res[i] = round(a_cpx[i].real());
        if (res[i]) {
            res[i] = 1;
        }
    }
    return res;
}

vector<int> calc_vec_power(vector<int> &a, int b) {
    vector<int> res(1024);
    res[0] = 1;

    while (b > 0) {
        if (b & 1) {
            res = calc_vec_mul(res, a);
        }
        a = calc_vec_mul(a, a);
        b >>= 1;
    }

    return res;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    vector<int> p(1024, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[x] = 1;
    }

    p = calc_vec_power(p, k);

    for (int i = 0; i < SIZE(p); i++) {
        if (p[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}
