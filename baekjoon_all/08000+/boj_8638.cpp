// Solve 2025-09-07

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

    int n;
    cin >> n;
    int scores[30];
    int max_score = 0;

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
        max_score = max(max_score, scores[i]);
    }

    string res;

    for (int i = 0; i < n; i++) {
        if (scores[i] == max_score) {
            res.push_back('A' + i);
        }
    }

    cout << res << '\n';
    return 0;
}
