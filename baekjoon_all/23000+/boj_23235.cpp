// Solve 2023-11-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int ti = 0;

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
        }

        cout << "Case " << ++ti << ": Sorting... done!\n";
    }

    return 0;
}
