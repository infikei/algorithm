// Solve 2023-02-10
// Update 2025-10-06

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

int a[100001];
int b[100001];
int c[100001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b[x] = i;
    }

    for (int i = 1; i <= n; i++) {
        c[i] = b[a[i]];
    }

    // 이제 LIS 문제로 바뀌었다.
    vector<int> memo;
    memo.push_back(c[1]);

    for (int i = 2; i <= n; i++) {
        int pos = lower_bound(memo.begin(), memo.end(), c[i]) - memo.begin();

        if (pos == size(memo)) {
            memo.push_back(c[i]);
        }
        else if (c[i] < memo[pos]) {
            memo[pos] = c[i];
        }
    }

    cout << size(memo) << '\n';
    return 0;
}
