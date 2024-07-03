// Solve 2023-07-31
// Update 2024-03-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    for (int ti = 0; ti < 100; ti++) {
        int cnt = 0;

        for (int i = 0; i < 5000; i++) {
            double d;
            cin >> d;

            if (d < 0.05) cnt++;
        }

        if (cnt > 180) cout << "A\n";
        else cout << "B\n";
    }

    return 0;
}
