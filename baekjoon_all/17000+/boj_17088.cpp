// Solve 2025-06-18
// Update 2025-12-23

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
int arr[100000];

int count_to_change(int d0, int d1) {
    int a0 = arr[0] + d0;
    int a1 = arr[1] + d1;
    int cnt = (d0 == 0 ? 0 : 1) + (d1 == 0 ? 0 : 1);
    int d = a1 - a0;
    int cur = a1;

    for (int i = 2; i < n; i++) {
        cur += d;

        if (arr[i] == cur) {
            continue;
        }
        if (arr[i] == cur - 1 || arr[i] == cur + 1) {
            cnt++;
            continue;
        }

        return INF;
    }

    return cnt;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n <= 2) {
        cout << 0 << '\n';
        return 0;
    }

    int mn = INF;

    for (int d0 = -1; d0 <= 1; d0++) {
        for (int d1 = -1; d1 <= 1; d1++) {
            mn = min(mn, count_to_change(d0, d1));
        }
    }

    cout << (mn == INF ? -1 : mn) << '\n';
    return 0;
}
