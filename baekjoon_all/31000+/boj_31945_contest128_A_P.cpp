// Solve 2024-06-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        bool flag = false;

        for (int i = 0; i <= 2; i++) {
            int aa = (a >> i) & 1;
            int bb = (b >> i) & 1;
            int cc = (c >> i) & 1;
            int dd = (d >> i) & 1;

            if (aa == bb && aa == cc && aa == dd) {
                flag = true;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}
