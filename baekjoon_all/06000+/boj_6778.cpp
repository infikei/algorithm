// Solve 2022-11-02
// Update 2023-10-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int antenna, eyes;
    cin >> antenna >> eyes;

    if (antenna >= 3 && eyes <= 4) {
        cout << "TroyMartian\n";
    }

    if (antenna <= 6 && eyes >= 2) {
        cout << "VladSaturnian\n";
    }

    if (antenna <= 2 && eyes <= 3) {
        cout << "GraemeMercurian\n";
    }

    return 0;
}
