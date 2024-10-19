// Solve 2024-10-18

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

int main() {
    FASTIO;

    int n, k;
    double s0;
    cin >> n >> s0 >> k;

    int pos = 1;
    double ans = 0;

    while (k-- > 0) {
        int mi;
        double si;
        cin >> mi >> si;

        ans += 240 * (mi - pos) / s0;
        pos = mi;
        s0 = si;
    }

    ans += 240 * (n + 1 - pos) / s0;

    setp(12);
    println(ans);

    return 0;
}
