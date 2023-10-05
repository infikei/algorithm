// Solve 2023-10-04

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        double v, w, f;
        cin >> v >> w >> f;

        if (v == 0 && w == 0 && f == 0) break;

        bool flag = false;

        if (v <= 4.5 && w >= 150 && f >= 200) {
            flag = true;

            cout << "Wide Receiver";
        }

        if (v <= 6.0 && w >= 300 && f >= 500) {
            if (flag) cout << ' ';
            else flag = true;

            cout << "Lineman";
        }

        if (v <= 5.0 && w >= 200 && f >= 300) {
            if (flag) cout << ' ';
            else flag = true;

            cout << "Quarterback";
        }

        if (!flag) {
            cout << "No positions";
        }

        cout << '\n';
    }

    return 0;
}
