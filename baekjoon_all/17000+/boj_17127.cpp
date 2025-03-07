// Solve 2025-03-06

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

int blossom[11];

int get_blossom_prod(int from, int to) {
    int res = 1;

    for (int i = from; i <= to; i++) {
        res *= blossom[i];
    }

    return res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> blossom[i];
    }

    int ans = 0;

    for (int i = 1; i < n; i++) {
        int a = get_blossom_prod(1, i);

        for (int j = i + 1; j < n; j++) {
            int b = get_blossom_prod(i + 1, j);

            for (int k = j + 1; k < n; k++) {
                int c = get_blossom_prod(j + 1, k);
                int d = get_blossom_prod(k + 1, n);

                ans = max(ans, a + b + c + d);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
