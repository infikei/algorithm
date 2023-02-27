// Solve 2023-02-25
// Update 2023-02-27

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
const int MAX_SIZE = 1000001;
const int FFT_SIZE = (1 << 21);

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

void fft_mul(vector<cpx> &a) {
    fft(a);
    for (int i = 0; i < FFT_SIZE; i++) {
        a[i] *= a[i];
    }
    fft(a, true);
}

int main() {
    FASTIO;

    vector<int> p(MAX_SIZE, 1);
    p[0] = p[1] = 0;
    for (int i = 2; i < MAX_SIZE; i++) {
        if (p[i] == 1) {
            for (int j = (i << 1); j < MAX_SIZE; j += i) {
                p[j] = 0;
            }
        }
    }

    vector<cpx> cpx_p2(ALL(p));
    cpx_p2.resize(FFT_SIZE);
    fft_mul(cpx_p2);
    vector<int> p2(MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        p2[i] = round(cpx_p2[i].real());
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;
        cout << ((p2[n] + p[(n >> 1)]) >> 1) << '\n';
    }

    return 0;
}