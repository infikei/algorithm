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

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        if (ti >= 2) cout << '\n';

        cout << "Data Set " << ti << ":\n";

        int e, a;
        cin >> e >> a;

        if (e <= a) {
            cout << "no drought\n";
        }
        else {
            int cnt = 0;
            int aa = a * 5;

            while (e > aa) {
                aa *= 5;
                cnt++;
            }

            for (int i = 0; i < cnt; i++) {
                cout << "mega ";
            }

            cout << "drought\n";
        }
    }

    return 0;
}
