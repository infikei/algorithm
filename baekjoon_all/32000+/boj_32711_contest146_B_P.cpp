// Solve 2024-11-24

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

int n;
int a[200000];

int solve() {
    ll a_sum = 0;
    ll even_group_cnt = 0;

    for (int i = 0; i < n; i++) {
        a_sum += a[i];

        if (a_sum % 2 == 0) {
            even_group_cnt++;
        }
    }

    if (a_sum % 2 == 1) {
        return 1;
    }

    if (even_group_cnt >= 2) {
        return 1;
    }

    return 0;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    println(solve());

    return 0;
}
