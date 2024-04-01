// Solve 2024-03-31

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
        int a, b;
        cin >> a >> b;

        int tmp = 0;

        while (true) {
            if (b < 3 * a) {
                cout << 3 * a - b + tmp << '\n';
                break;
            }
            else if (b <= 4 * a) {
                cout << tmp << '\n';
                break;
            }

            a++;
            tmp++;
        }
    }

    return 0;
}
