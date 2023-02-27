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
const int FFT_SIZE = (1 << 3);

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

void fft_mul(vector<cpx> &a, vector<cpx> &b, vector<cpx> &res) {
    fft(a);
    fft(b);
    for (int i = 0; i < FFT_SIZE; i++) {
        res[i] = a[i] * b[i];
    }
    fft(res, true);
}

int main() {
    FASTIO;

    vector<int> a = { 1, 2, 1 };
    vector<int> b = { 1, 2, 1 };

    vector<cpx> cpx_a(ALL(a)), cpx_b(ALL(b)), cpx_res(FFT_SIZE);
    cpx_a.resize(FFT_SIZE);
    cpx_b.resize(FFT_SIZE);
    fft_mul(cpx_a, cpx_b, cpx_res);

    vector<int> res(SIZE(a) + SIZE(b) - 1);
    for (int i = 0; i < SIZE(res); i++) {
        res[i] = round(cpx_res[i].real());
    }

    for (auto i : res) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}