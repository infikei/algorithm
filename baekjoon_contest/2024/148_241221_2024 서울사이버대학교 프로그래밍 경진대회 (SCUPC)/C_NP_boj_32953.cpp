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

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        while (k-- > 0) {
            int id;
            cin >> id;

            umap[id]++;
        }
    }

    int cnt = 0;

    for (auto it = umap.begin(); it != umap.end(); it++) {
        if (it->second >= m) {
            cnt++;
        }
    }

    println(cnt);

    return 0;
}
