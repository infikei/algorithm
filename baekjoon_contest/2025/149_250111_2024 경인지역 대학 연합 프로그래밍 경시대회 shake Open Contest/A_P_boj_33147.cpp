// Solve 2025-01-11

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

int get_gcd(int a, int b) {
    int r = a % b;

    return r == 0 ? b : get_gcd(b, r);
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    if (k != n) {
        k = get_gcd(k, n - k);
    }

    bool ans = true;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (abs(x - i) % k != 0) {
            ans = false;
        }
    }

    println(ans ? "YES" : "NO");

    return 0;
}
