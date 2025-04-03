// Solve 2025-04-02

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

const int MOD = 1000000007;

int arr[100001];
int tmp[100001];

inline int mod_add(int a, int b) {
    int res = a + b;
    return res >= MOD ? res - MOD : res;
}

inline int mod_sub(int a, int b) {
    int res = a - b;
    return res < 0 ? res + MOD : res;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        arr[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            tmp[j] = mod_add(tmp[j - 1], arr[j]);
        }

        for (int j = 2; j <= k; j++) {
            tmp[j] = mod_add(tmp[j], mod_sub(tmp[k], tmp[j]));

            for (int jj = j + j; jj <= k; jj += j) {
                tmp[j] = mod_sub(tmp[j], arr[jj]);
            }
        }

        swap(arr, tmp);
    }

    int ans = 0;

    for (int i = 1; i <= k; i++) {
        ans = mod_add(ans, arr[i]);
    }

    cout << ans << '\n';

    return 0;
}
