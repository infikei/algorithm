// Solve 2023-12-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int p, r;
    cin >> p >> r;

    if (p * 5 < r) {
        cout << "weak\n";
    }
    else if (p * 5 < r * 2) {
        cout << "normal\n";
    }
    else if (p * 5 < r * 3) {
        cout << "strong\n";
    }
    else {
        cout << "very strong\n";
    }

    return 0;
}
