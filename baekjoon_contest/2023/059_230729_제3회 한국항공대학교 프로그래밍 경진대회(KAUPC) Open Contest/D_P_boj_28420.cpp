// Solve 2023-07-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int cloud[301][301];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;

            cloud[i][j] = -cloud[i - 1][j - 1] + cloud[i - 1][j] + cloud[i][j - 1] + x;
        }
    }

    int ans = 1e9;

    int ab = a + b;
    int ac = a + c;
    int bc = b + c;

    for (int i = a; i <= n; i++) {
        int ia = i - a;
        for (int j = bc; j <= m; j++) {
            int jbc = j - bc;
            ans = min(ans, cloud[ia][jbc] - cloud[ia][j] - cloud[i][jbc] + cloud[i][j]);
        }
    }

    for (int i = ab; i <= n; i++) {
        int iab = i - ab, ib = i - b;
        for (int j = ac; j <= m; j++) {
            int jac = j - ac, ja = j - a;
            ans = min(ans, cloud[iab][jac] - cloud[iab][ja] - cloud[ib][jac] + cloud[ib][ja] + cloud[ib][ja] - cloud[ib][j] - cloud[i][ja] + cloud[i][j]);
        }
    }

    for (int i = ac; i <= n; i++) {
        int iac = i - ac, ic = i - c;
        for (int j = ab; j <= m; j++) {
            int jab = j - ab, ja = j - a;
            ans = min(ans, cloud[iac][jab] - cloud[iac][ja] - cloud[ic][jab] + cloud[ic][ja] + cloud[ic][ja] - cloud[ic][j] - cloud[i][ja] + cloud[i][j]);
        }
    }

    cout << ans << '\n';

    return 0;
}
