// Solve 2022-06-03
// Update 2026-02-15

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    unordered_set<string> words_set;

    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        words_set.insert(w);
    }

    int cnt = 0;

    for (int i = 0; i < m; i++) {
        string w;
        cin >> w;

        if (words_set.find(w) != words_set.end()) {
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
