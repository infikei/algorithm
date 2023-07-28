// Solve 2022-08-02
// Update 2023-07-28

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

    if (n % 2 == 1) {
        cout << "SK\n";
    }
    else {
        cout << "CY\n";
    }

    return 0;
}
