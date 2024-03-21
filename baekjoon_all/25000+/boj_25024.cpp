// Solve 2024-03-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int month_day[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int t;
    cin >> t;

    while (t-- > 0) {
        int x, y;
        cin >> x >> y;

        if (x <= 23 && y <= 59) {
            cout << "Yes ";
        }
        else {
            cout << "No ";
        }

        if (x >= 1 && x <= 12 && y >= 1 && y <= month_day[x]) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}
