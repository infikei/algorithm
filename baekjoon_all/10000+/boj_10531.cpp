// Solve 2023-02-25

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

void fft(vector<cpx> &a, bool inv) {
    int n = SIZE(a);

    // 기존 코드는 배열의 추가적인 생성으로 인해 메모리 낭비가 발생했다.
    // 이를 방지하기 위해 bit reversal을 이용하여 a 수열을 재배열한다.
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        j ^= bit;
        while (!(j & bit)) {
            bit >>= 1;
            j ^= bit;
        }
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    // 재귀 방식 대신 비재귀 방식으로 FFT를 구현할 수 있다.
    // 여기서 k * 2는 FFT를 수행할 공간의 크기가 된다. (k * 2 = 2, 4, 8, ...)
    for (int k = 1; k < n; k <<= 1) {
        double theta = (inv ? -PI / k : PI / k);
        cpx w(cos(theta), sin(theta));

        int k2 = k * 2;
        for (int i = 0; i < n; i += k2) {
            cpx w_pow(1, 0);
            for (int j = 0; j < k; j++) {
                cpx even = a[i + j];
                cpx odd = a[k + i + j];
                a[i + j] = even + odd * w_pow;
                a[k + i + j] = even - odd * w_pow;
                w_pow *= w;
            }
        }
    }

    // Inverse FFT일 때는 n으로 나누어주어야 한다.
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

    int n;
    cin >> n;

    vector<int> a(200001);
    a[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    vector<int> b = fft_mul(a, a);

    int m;
    cin >> m;

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (b[x] > 0) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}