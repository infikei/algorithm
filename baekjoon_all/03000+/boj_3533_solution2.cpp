// Solve 2023-10-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int cnt = 0;

    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;

        if (x == 1) cnt++;
    }

    if (cnt == 0 || cnt == 4 || cnt == 8) {
        cout << 0 << '\n';
    }
    else {
        cout << 1 << '\n';
    }

    return 0;
}
