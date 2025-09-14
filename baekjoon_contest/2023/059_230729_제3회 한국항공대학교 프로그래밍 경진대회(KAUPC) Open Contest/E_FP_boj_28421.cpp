// Solve 2025-09-14

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

int n;
int a[100001];
int cnt[10001];

int find(int x) {
    if (x == 0) {
        if (cnt[0] >= 1 && n >= 2) {
            return 1;
        }

        return 0;
    }

    int sqrt_x = sqrt(x);

    if (sqrt_x * sqrt_x == x && cnt[sqrt_x] >= 2) {
        return 1;
    }

    for (int i = 1; i <= sqrt_x; i++) {
        if (x % i != 0) continue;

        int j = x / i;

        if (i == j || j > 10000) continue;

        if (cnt[i] >= 1 && cnt[j] >= 1) {
            return 1;
        }
    }

    return 0;
}

int main() {
    FASTIO;

    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    while (q-- > 0) {
        int cmd, x;
        cin >> cmd >> x;

        if (cmd == 1) {
            cout << find(x) << '\n';
        }
        else {
            cnt[a[x]]--;
            cnt[0]++;
            a[x] = 0;
        }
    }

    return 0;
}
