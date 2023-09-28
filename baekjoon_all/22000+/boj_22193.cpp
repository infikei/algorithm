// Solve 2023-09-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using cpx = complex<double>;

const double PI = acos(-1);

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
    int n = SIZE(a) + SIZE(b) - 1;
    int n2 = 1;

    while (n2 <= n) {
        n2 <<= 1;
    }

    vector<cpx> aa(a.begin(), a.end()), bb(b.begin(), b.end());
    aa.resize(n2);
    bb.resize(n2);
    fft(aa);
    fft(bb);

    for (int i = 0; i < n2; i++) {
        aa[i] *= bb[i];
    }

    fft(aa, true);

    res.assign(n, 0);

    for (int i = 0; i < n; i++) {
        res[i] = round(aa[i].real());
    }
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    vector<int> aa, bb;

    for (char &i : a) {
        aa.push_back(i - '0');
    }

    for (char &i : b) {
        bb.push_back(i - '0');
    }

    vector<int> res;

    fft_mul(aa, bb, res);

    int carry = 0;

    for (int i = SIZE(res) - 1; i >= 0; i--) {
        res[i] += carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }

    string ans;
    int pos = 0;

    if (carry == 0) {
        while (pos + 1 < SIZE(res) && res[pos] == 0) {
            pos++;
        }
    }
    else {
        ans = to_string(carry);
    }

    for (int i = pos, ie = SIZE(res); i < ie; i++) {
        ans.push_back('0' + res[i]);
    }

    cout << ans << '\n';

    return 0;
}
