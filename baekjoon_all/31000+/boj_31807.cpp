// Solve 2024-12-22

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int get_kmp_failure(vector<int> &p) {
    int m = size(p);
    vector<int> f(m, 0);

    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = f[j - 1];
        }

        if (p[i] == p[j]) {
            j++;
            f[i] = j;
        }
    }

    return f.back();
}

int main() {
    FASTIO;

    int l;
    cin >> l;

    vector<int> integrals(l);

    for (int &i : integrals) {
        cin >> i;
    }

    int a, b;
    cin >> a >> b;

    int period = l - get_kmp_failure(integrals);

    vector<ll> prefix_sum(period);
    prefix_sum[0] = integrals[0];

    for (int i = 1; i < period; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + integrals[i];
    }

    if (a < 0) {
        int diff = (-a - 1) / period * period + period * 2;
        a += diff;
        b += diff;
    }

    ll from_0_to_b = (b - 1) / period * prefix_sum[period - 1] + prefix_sum[(b - 1) % period];
    ll from_0_to_a = (a - 1) / period * prefix_sum[period - 1] + prefix_sum[(a - 1) % period];

    println(from_0_to_b - from_0_to_a);

    return 0;
}
