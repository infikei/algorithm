// Solve 2022-12-09
// Update 2025-07-26

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

int arr[102400];
int len_sqrt = 320;
int memo_sqrt[320]; // sqrt decomposition

int get_min_between(int a, int b) {
    int ret = INF;

    if (a / len_sqrt == b / len_sqrt) {
        for (int i = a; i <= b; i++) {
            ret = min(ret, arr[i]);
        }
        return ret;
    }

    while (a % len_sqrt != 0) {
        ret = min(ret, arr[a]);
        a++;
    }
    while (b % len_sqrt != len_sqrt - 1) {
        ret = min(ret, arr[b]);
        b--;
    }
    for (int i = a / len_sqrt; i <= b / len_sqrt; i++) {
        ret = min(ret, memo_sqrt[i]);
    }
    return ret;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    memset(memo_sqrt, 0x3f, sizeof memo_sqrt);

    for (int i = 0; i < len_sqrt; i++) {
        for (int j = 0; j < len_sqrt; j++) {
            memo_sqrt[i] = min(memo_sqrt[i], arr[i * len_sqrt + j]);
        }
    }

    while (m-- > 0) {
        int a, b;
        cin >> a >> b;
        cout << get_min_between(a, b) << '\n';
    }

    return 0;
}
