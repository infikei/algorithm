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
const int MAX_N = 1000001;
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

    vector<int> v1(MAX_N, 1);
    v1[0] = v1[1] = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (v1[i] == 1) {
            for (int j = (i << 1); j < MAX_N; j += i) {
                v1[j] = 0;
            }
        }
    }
    v1[2] = 0;

    // v2 구하기

    vector<cpx> fft1(ALL(v1));
    fft1.resize(FFT_SIZE);
    fft(fft1, false);

    vector<cpx> fft2(FFT_SIZE);
    for (int i = 0; i < FFT_SIZE; i++) {
        fft2[i] = fft1[i] * fft1[i];
    }
    fft(fft2, true);

    vector<int> v2(MAX_N);
    for (int i = 0; i < MAX_N; i++) {
        v2[i] = round(fft2[i].real());
    }

    // v2 수정, v3 구하기

    vector<int> v3(MAX_N);
    for (int i = 2; i < MAX_N; i += 2) {
        v3[i] = v1[(i >> 1)];
        v2[i] -= v3[i];
        v2[i] >>= 1;
    }

    // v6 구하기

    vector<int> v6(MAX_N);
    for (int i = 1, i_end = MAX_N / 3; i < i_end; i++) {
        v6[i * 3] = v1[i];
    }

    // v5 구하기 (공간 절약을 위해 v3 재활용)

    fft2.assign(ALL(v3));
    fft2.resize(FFT_SIZE);
    fft(fft2, false);

    for (int i = 0; i < FFT_SIZE; i++) {
        fft2[i] *= fft1[i];
    }
    fft(fft2, true);

    for (int i = 0; i < MAX_N; i++) {
        v3[i] = round(fft2[i].real());
        v3[i] -= v6[i];
    }

    // v4 구하기 (공간 절약을 위해 v2 재활용)

    fft2.assign(ALL(v2));
    fft2.resize(FFT_SIZE);
    fft(fft2, false);

    for (int i = 0; i < FFT_SIZE; i++) {
        fft2[i] *= fft1[i];
    }
    fft(fft2, true);

    for (int i = 0; i < MAX_N; i++) {
        v2[i] = round(fft2[i].real());
        v2[i] = (v2[i] - v3[i]) / 3;
    }

    for (int i = 7; i < MAX_N; i++) {
        v2[i] += (v3[i] + v6[i] + v1[i - 4]);
    }



    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;
        cout << v2[n] << '\n';
    }

    return 0;
}