// Solve 2024-12-02
// Update 2025-02-18

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

int ports[40000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ports[i];
    }

    vector<int> memo;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(memo.begin(), memo.end(), ports[i]);

        if (it == memo.end()) {
            memo.push_back(ports[i]);
        }
        else {
            *it = ports[i];
        }
    }

    cout << size(memo) << '\n';

    return 0;
}
