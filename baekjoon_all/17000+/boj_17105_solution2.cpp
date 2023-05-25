// Solve 2023-02-27
// Update 2023-02-28

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
    p[2] = 0;

    vector<int> q(MAX_SIZE);
    for (int i = 2; i < MAX_SIZE; i += 2) {
        q[i] = p[(i >> 1)];
    }



    vector<cpx> cpx_p(ALL(p)), cpx_p3(FFT_SIZE);
    cpx_p.resize(FFT_SIZE);
    fft(cpx_p);
    for (int i = 0; i < FFT_SIZE; i++) {
        cpx_p3[i] = cpx_p[i] * cpx_p[i];
    }
    fft(cpx_p3, true);
    cpx_p3.resize(MAX_SIZE);
    cpx_p3.resize(FFT_SIZE);
    fft(cpx_p3);
    for (int i = 0; i < FFT_SIZE; i++) {
        cpx_p3[i] *= cpx_p[i];
    }
    fft(cpx_p3, true);

    vector<int> p3(MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        p3[i] = round(cpx_p3[i].real());
    }



    vector<cpx> cpx_q(ALL(q));
    cpx_q.resize(FFT_SIZE);
    fft(cpx_q);
    for (int i = 0; i < FFT_SIZE; i++) {
        cpx_q[i] *= cpx_p[i];
    }
    fft(cpx_q, true);

    for (int i = 0; i < MAX_SIZE; i++) {
        q[i] = round(cpx_q[i].real());
    }



    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;
        int c = 0;
        if (n % 3 == 0 && p[n / 3] == 1) {
            c = 2;
        }
        cout << (p3[n] - q[n] * 3 + c) / 6 + q[n] + p[n - 4] << '\n';
    }

    return 0;
}