#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using cpx = complex<double>;

const double PI = acos(-1);

void fft(vector<cpx> &a, bool inv, bool recursion = false) {
    int n = SIZE(a);
    if (n == 1) return;

    int n2 = n / 2;

    vector<cpx> even_elements(n2), odd_elements(n2);
    for (int i = 0; i < n2; i++) {
        even_elements[i] = a[i * 2];
        odd_elements[i] = a[i * 2 + 1];
    }
    fft(even_elements, inv, true);
    fft(odd_elements, inv, true);

    double theta = (inv ? -2 * PI / n : 2 * PI / n);
    cpx w(cos(theta), sin(theta));
    cpx w_pow(1, 0);
    for (int i = 0; i < n2; i++) {
        a[i] = even_elements[i] + odd_elements[i] * w_pow;
        a[n2 + i] = even_elements[i] - odd_elements[i] * w_pow;
        w_pow *= w;
    }

    if (!recursion && inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}

vector<int> fft_mul(const vector<int> &a, const vector<int> &b) {
    vector<cpx> a2(a.begin(), a.end());
    vector<cpx> b2(b.begin(), b.end());

    int n2 = 1;
    while (n2 < SIZE(a) + SIZE(b)) {
        n2 <<= 1;
    }
    a2.resize(n2);
    fft(a2, false);
    b2.resize(n2);
    fft(b2, false);

    for (int i = 0; i < n2; i++) {
        a2[i] *= b2[i];
    }
    fft(a2, true);

    int n = SIZE(a) + SIZE(b) - 1;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = round(a2[i].real());
    }

    return c;
}

int main() {
    FASTIO;

    vector<int> a = { 1, 2, 1 };
    vector<int> b = { 1, 2, 1 };

    vector<int> c = fft_mul(a, b);
    for (auto i : c) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}