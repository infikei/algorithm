// Solve 2025-05-11

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

ll arr[100000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    while (m-- > 0) {
        int cmd, ans;
        ll i, j, k;
        cin >> cmd;

        switch (cmd) {
            case 1:
                cin >> k;

                ans = (arr + n) - lower_bound(arr, arr + n, k);
                cout << ans << '\n';
                break;

            case 2:
                cin >> k;

                ans = (arr + n) - upper_bound(arr, arr + n, k);
                cout << ans << '\n';
                break;

            case 3:
                cin >> i >> j;

                ans = upper_bound(arr, arr + n, j) - lower_bound(arr, arr + n, i);
                cout << ans << '\n';
                break;
        }
    }

    return 0;
}
