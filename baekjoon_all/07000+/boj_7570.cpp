// Solve 2025-08-16

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
        int x;
        cin >> x;
        arr[x] = i;
    }

    int max_asc = 0;
    int cur_asc = 0;
    int prev = -1;

    for (int i = 1; i <= n; i++) {
        if (arr[i] > prev) {
            cur_asc++;
        }
        else {
            max_asc = max(max_asc, cur_asc);
            cur_asc = 1;
        }

        prev = arr[i];
    }

    max_asc = max(max_asc, cur_asc);
    cout << n - max_asc << '\n';
    return 0;
}
