// Solve 2023-06-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using ld = long double;
using cpx = complex<ld>;

const double PI = M_PI;
const int FFT_SIZE = 1 << 21;

void fft(vector<cpx> &a, bool inv = false) {
    int n = SIZE(a);

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }

    for (int k = 1; k < n; k <<= 1) {
        ld theta = (inv ? -PI / k : PI / k);
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
        for (int i = 0; i < n; i++) a[i] /= n;
    }
}

void fft_mul(const vector<ll> &a, const vector<ll> &b, vector<ll> &res) {
    vector<cpx> aa(a.begin(), a.end());
    vector<cpx> bb(b.begin(), b.end());

    fft(aa);
    fft(bb);
    for (int i = 0; i < FFT_SIZE; i++) aa[i] *= bb[i];
    fft(aa, true);

    res.assign(FFT_SIZE, 0);
    for (int i = 0; i < FFT_SIZE; i++) res[i] = round(aa[i].real());
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    vector<ll> a(FFT_SIZE, 0), b(FFT_SIZE, 0);
    for (int i = 0; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= m; i++) cin >> b[i];

    vector<ll> aa = a, bb = b;
    for (int i = 0; i < FFT_SIZE; i++) aa[i] >>= 10;
    for (int i = 0; i < FFT_SIZE; i++) bb[i] >>= 10;
    vector<ll> c1;
    fft_mul(aa, bb, c1);

    aa = a, bb = b;
    for (int i = 0; i < FFT_SIZE; i++) aa[i] >>= 10;
    for (int i = 0; i < FFT_SIZE; i++) bb[i] &= 1023;
    vector<ll> c2;
    fft_mul(aa, bb, c2);

    aa = a, bb = b;
    for (int i = 0; i < FFT_SIZE; i++) aa[i] &= 1023;
    for (int i = 0; i < FFT_SIZE; i++) bb[i] >>= 10;
    vector<ll> c3;
    fft_mul(aa, bb, c3);

    aa = a, bb = b;
    for (int i = 0; i < FFT_SIZE; i++) aa[i] &= 1023;
    for (int i = 0; i < FFT_SIZE; i++) bb[i] &= 1023;
    vector<ll> c4;
    fft_mul(aa, bb, c4);

    ll ans = 0;
    for (int i = 0; i < FFT_SIZE; i++) {
        ans ^= (c1[i] << 20) + ((c2[i] + c3[i]) << 10) + c4[i];
    }
    cout << ans << '\n';

    return 0;
}
