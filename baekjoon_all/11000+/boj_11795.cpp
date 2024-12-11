// Solve 2024-12-10

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

    int cnt[3] = { 0 };

    while (t-- > 0) {
        for (int i = 0; i < 3; i++) {
            int x;
            cin >> x;

            cnt[i] += x;
        }

        int d = min(cnt[0], min(cnt[1], cnt[2]));

        if (d < 30) {
            println("NO");
        }
        else {
            println(d);

            for (int i = 0; i < 3; i++) {
                cnt[i] -= d;
            }
        }
    }

    return 0;
}
