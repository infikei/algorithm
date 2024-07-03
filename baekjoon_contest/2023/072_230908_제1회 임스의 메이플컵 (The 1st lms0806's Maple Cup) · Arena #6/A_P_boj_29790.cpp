// Solve 2023-09-08
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, u, l;
    cin >> n >> u >> l;

    if (n >= 1000) {
        if (u >= 8000 || l >= 260) {
            cout << "Very Good\n";
        }
        else {
            cout << "Good\n";
        }
    }
    else {
        cout << "Bad\n";
    }

    return 0;
}
