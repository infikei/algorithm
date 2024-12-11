// Solve 2024-12-11

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

bool visited[1001];

int main() {
    FASTIO;

    int l, n;
    cin >> l >> n;

    int max_cnt = 0;
    int max_spectator = 1;

    int max_expected_cnt = 0;
    int max_expected_spectator = 1;

    for (int u = 1; u <= n; u++) {
        int p, k;
        cin >> p >> k;

        int expected_cnt = k - p + 1;

        if (expected_cnt > max_expected_cnt) {
            max_expected_cnt = expected_cnt;
            max_expected_spectator = u;
        }

        int cnt = 0;

        for (int i = p; i <= k; i++) {
            if (!visited[i]) {
                visited[i] = true;
                cnt++;
            }
        }

        if (cnt > max_cnt) {
            max_cnt = cnt;
            max_spectator = u;
        }
    }

    println(max_expected_spectator);
    println(max_spectator);

    return 0;
}
