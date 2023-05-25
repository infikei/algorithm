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

vector<int> fft_mul(const vector<int> &a, const vector<int> &b) {
    int n = SIZE(a) + SIZE(b) - 1;
    int n2 = 1;
    while (n2 <= n) {
        n2 <<= 1;
    }

    vector<cpx> a2(a.begin(), a.end());
    a2.resize(n2);
    fft(a2, false);

    vector<cpx> b2(b.begin(), b.end());
    b2.resize(n2);
    fft(b2, false);

    for (int i = 0; i < n2; i++) {
        a2[i] *= b2[i];
    }
    fft(a2, true);

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = round(a2[i].real());
    }

    return c;
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

    vector<int> v2 = fft_mul(v1, v1);
    v2.resize(MAX_N);

    // 이 시점에서 v2 : (a + a)를 2번 count + (a + b)를 1번 count

    vector<int> v3(MAX_N);
    for (int i = 2; i < MAX_N; i += 2) {
        v3[i] = v1[(i >> 1)];
        v2[i] -= v3[i];
        v2[i] >>= 1;
    }

    // 이 시점에서 v2 : (a + b)를 1번 count
    // 이 시점에서 v3 : (a + a)를 1번 count

    vector<int> v6(MAX_N);
    for (int i = 1, i_end = MAX_N / 3; i < i_end; i++) {
        v6[i * 3] = v1[i];
    }

    // 이 시점에서 v6 : (a + a + a)를 1번 count

    vector<int> v5 = fft_mul(v3, v1);
    v5.resize(MAX_N);
    for (int i = 9; i < MAX_N; i++) {
        v5[i] -= v6[i];
    }

    // 이 시점에서 v5 : (a + a + b)를 1번 count

    vector<int> v4 = fft_mul(v2, v1);
    v4.resize(MAX_N);
    for (int i = 11; i < MAX_N; i++) {
        v4[i] -= v5[i];
        v4[i] /= 3;
    }

    // 이 시점에서 v4 : (a + b + c)를 1번 count

    for (int i = 7; i < MAX_N; i++) {
        v4[i] += (v5[i] + v6[i] + v1[i - 4]);
    }



    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;
        cout << v4[n] << '\n';
    }

    return 0;
}