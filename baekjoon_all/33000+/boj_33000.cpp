// Solve 2025-01-13

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

int get_bit_cnt(ll k) {
    int bit_cnt = 0;

    while (k > 0) {
        if (k & 1) {
            bit_cnt++;
        }

        k >>= 1;
    }

    return bit_cnt;
}

int main() {
    FASTIO;

    ll a, b;
    cin >> a >> b;

    int a_bit_cnt = get_bit_cnt(a);
    int i = 0;

    while (a_bit_cnt > 1) {
        while ((a & (1ll << i)) == 0) {
            i++;
        }

        ll cur = a;
        int cur_bit_cnt = get_bit_cnt(cur);

        while (cur_bit_cnt == a_bit_cnt) {
            cur += (1ll << i);
            cur_bit_cnt = get_bit_cnt(cur);
            i++;
        }

        if (cur > b) break;

        a = cur;
        a_bit_cnt = cur_bit_cnt;
    }

    println(a);

    return 0;
}
