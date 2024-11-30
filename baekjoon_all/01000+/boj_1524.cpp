// Solve 2024-11-29

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
        int n, m;
        cin >> n >> m;

        int max_s = 0;
        int max_b = 0;

        for (int i = 0; i < n; i++) {
            int s;
            cin >> s;

            max_s = max(max_s, s);
        }

        for (int i = 0; i < m; i++) {
            int b;
            cin >> b;

            max_b = max(max_b, b);
        }

        println(max_s >= max_b ? "S" : "B");
    }

    return 0;
}
