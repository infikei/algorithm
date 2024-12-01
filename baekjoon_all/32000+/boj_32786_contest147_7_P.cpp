// Solve 2024-11-30

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

    int n, c, k;
    cin >> n >> c >> k;

    vector<int> r(k);

    for (int &ri : r) {
        cin >> ri;
    }

    sort(all(r));

    for (int i = 0; i < c; i++) {
        int from = 1;

        for (int &ri : r) {
            int cnt = ri - from + 1;

            for (int j = 0; j < cnt; j++) {
                printw(from + (j + i) % cnt);
            }

            from = ri + 1;
        }

        int cnt = (n + 1) - from + 1;

        for (int j = 0; j < cnt - 1; j++) {
            printw(from + (j + i) % cnt);
        }

        cout << '\n';
    }

    return 0;
}
