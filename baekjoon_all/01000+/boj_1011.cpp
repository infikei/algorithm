// Solve 2023-01-25
// Update 2024-11-02

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

    int t;
    cin >> t;

    while (t-- > 0) {
        ll x, y;
        cin >> x >> y;

        y -= x;

        // 1 + 2 + ... + n + ... + 2 + 1 = n^2
        // 즉, n^2 칸을 이동하기 위해서는 (2n-1)번 이동해야 한다.
        // 또한 남는 y-n^2(사실은 y-x-n^2) 칸에 대해서는 n으로 나눠준 나머지 값을 이용하여 추가로 더해준다.

        ll n = 1;

        while (n * n <= y) n++;

        n--;

        ll ans = 2 * n - 1 + (y - n * n + n - 1) / n;

        println(ans);
    }

    return 0;
}
