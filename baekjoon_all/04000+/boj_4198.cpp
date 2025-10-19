// Solve 2025-10-18

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

int w[2000];
int r_lis[2000];
int r_lds[2000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<int> memo;

    for (int i = n - 1; i >= 0; i--) {
        int pos = lower_bound(memo.begin(), memo.end(), w[i]) - memo.begin();
        r_lis[i] = pos + 1;

        if (pos == size(memo)) {
            memo.push_back(w[i]);
        }
        else {
            memo[pos] = w[i];
        }
    }

    memo.clear();

    for (int i = n - 1; i >= 0; i--) {
        int pos = lower_bound(memo.begin(), memo.end(), w[i], greater<int>()) - memo.begin();
        r_lds[i] = pos + 1;

        if (pos == size(memo)) {
            memo.push_back(w[i]);
        }
        else {
            memo[pos] = w[i];
        }
    }

    int mx = 0;

    for (int i = 0; i < n; i++) {
        mx = max(mx, r_lis[i] + r_lds[i] - 1);
    }

    cout << mx << '\n';
    return 0;
}
