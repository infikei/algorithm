// Solve 2023-10-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, p, h;
    cin >> n >> p >> h;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x < p) {
            cout << "NTV: Dollar dropped by " << p - x << " Oshloobs\n";
        }
        else if (x > h) {
            cout << "BBTV: Dollar reached " << x << " Oshloobs, A record!\n";
            h = x;
        }

        p = x;
    }

    return 0;
}
