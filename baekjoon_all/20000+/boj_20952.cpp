// Solve 2025-10-21

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

int arr[100000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int cnt[7] = {0};
    int cnt_sum = n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i] % 7]++;
    }

    ll b_sum = 0;

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        int d = 0;

        for (int j = 0; j < 7; j++) {
            if ((b_sum + b + j) % 7 == 0) {
                d = j;
                break;
            }
        }

        if (cnt_sum == cnt[d]) continue;

        cnt_sum -= cnt[d];
        cnt[d] = 0;
        b_sum += b;
    }

    cout << cnt_sum << '\n';

    for (int i = 0; i < n; i++) {
        if (cnt[arr[i] % 7] > 0) {
            cout << (arr[i] + b_sum) % MOD << ' ';
        }
    }

    cout << '\n';
    return 0;
}
