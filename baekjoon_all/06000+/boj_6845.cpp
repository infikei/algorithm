// Solve 2023-11-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int year, month, day;
        cin >> year >> month >> day;

        if (year <= 1988) {
            cout << "Yes\n";
        }
        else if (year >= 1990) {
            cout << "No\n";
        }
        else if (month == 1 || month == 2 && day <= 27) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}
