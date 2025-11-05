// Solve 2025-11-02

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

int n_score[6] = {0, 10, 20, 50, 60, 120};

int main() {
    FASTIO;

    int n, w;
    cin >> n >> w;

    int score = max(0, n_score[n] - (w > 1000 ? 15 : 0));
    cout << score << '\n';
    return 0;
}
