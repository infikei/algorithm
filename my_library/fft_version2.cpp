#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using cpx = complex<double>;

const double PI = M_PI;
const int FFT_SIZE = 1 << 3;

void fft(vector<cpx> &a, bool inv = false, bool recursion = false) {
    int n = SIZE(a);
    if (n == 1) return;
    int n2 = n >> 1;

    vector<cpx> even_elements(n2), odd_elements(n2);
    for (int i = 0; i < n2; i++) {
        even_elements[i] = a[i * 2];
        odd_elements[i] = a[i * 2 + 1];
    }
    fft(even_elements, inv, true);
    fft(odd_elements, inv, true);

    double theta = (inv ? -2 * PI / n : 2 * PI / n);
    cpx w(cos(theta), sin(theta));
    cpx wp(1, 0);
    for (int i = 0; i < n2; i++) {
        a[i] = even_elements[i] + odd_elements[i] * wp;
        a[n2 + i] = even_elements[i] - odd_elements[i] * wp;
        wp *= w;
    }

    if (!recursion && inv) {
        for (int i = 0; i < n; i++) a[i] /= n;
    }
}

void fft_mul(const vector<int> &a, const vector<int> &b, vector<int> &res) {
    vector<cpx> aa(a.begin(), a.end());
    vector<cpx> bb(b.begin(), b.end());

    int n = 1;
    while (n < SIZE(a) + SIZE(b)) n <<= 1;

    aa.resize(n);
    bb.resize(n);
    fft(aa);
    fft(bb);
    for (int i = 0; i < n; i++) aa[i] *= bb[i];
    fft(aa, true);

    res.assign(SIZE(a) + SIZE(b) - 1, 0);
    for (int i = 0; i < SIZE(res); i++) res[i] = round(aa[i].real());
}

int main() {
    FASTIO;

    vector<int> a = { 1, 2, 1 };
    vector<int> b = { 1, 2, 1 };

    vector<int> c;
    fft_mul(a, b, c);
    for (auto &i : c) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}