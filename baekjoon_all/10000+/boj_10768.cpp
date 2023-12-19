// Solve 2022-10-16
// Update 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int month, day;
    cin >> month >> day;

    int mmdd = month * 100 + day;

    if (mmdd < 218) {
        cout << "Before\n";
    }
    else if (mmdd > 218) {
        cout << "After\n";
    }
    else {
        cout << "Special\n";
    }

    return 0;
}
