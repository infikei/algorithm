#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using cpx = complex<double>;

const double PI = M_PI;
const int FFT_SIZE = 1 << 3;

void fft(vector<cpx> &a, bool inv = false) {
    int n = SIZE(a);

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }

    for (int k = 1; k < n; k <<= 1) {
        double theta = (inv ? -PI / k : PI / k);
        cpx w(cos(theta), sin(theta));

        int k2 = k << 1;

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

void fft_mul(const vector<int> &a, const vector<int> &b, vector<int> &res) {
    vector<cpx> aa(a.begin(), a.end());
    vector<cpx> bb(b.begin(), b.end());

    fft(aa);
    fft(bb);

    for (int i = 0; i < FFT_SIZE; i++) {
        aa[i] *= bb[i];
    }

    fft(aa, true);

    res.assign(FFT_SIZE, 0);

    for (int i = 0; i < FFT_SIZE; i++) {
        res[i] = round(aa[i].real());
    }
}

int main() {
    FASTIO;

    vector<int> a = { 1, 2, 1 };
    vector<int> b = { 1, 2, 1 };

    a.resize(FFT_SIZE);
    b.resize(FFT_SIZE);

    vector<int> res;

    fft_mul(a, b, res);

    for (int &i : res) {
        cout << i << ' ';
    }

    cout << '\n';

    return 0;
}
