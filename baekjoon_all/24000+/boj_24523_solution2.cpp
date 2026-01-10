// Solve 2026-01-06

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

int arr[1000001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;

    for (int i = 1; i < n; i++) {
        cnt++;

        if (arr[i] != arr[i + 1]) {
            while (cnt-- > 0) {
                cout << i + 1 << ' ';
            }

            cnt = 0;
        }
    }

    cnt++;

    while (cnt-- > 0) {
        cout << -1 << ' ';
    }

    cout << '\n';
    return 0;
}
