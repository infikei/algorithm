// Solve 2024-02-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int answers[12][2] = {
        { 0, 0 },
        { 12, 1600 },
        { 11, 894 },
        { 11, 1327 },
        { 10, 1311 },
        { 9, 1004 },
        { 9, 1178 },
        { 9, 1357 },
        { 8, 837 },
        { 7, 1055 },
        { 6, 556 },
        { 6, 773 }
    };

    int n;
    cin >> n;
    cout << answers[n][0] << ' ' << answers[n][1] << '\n';

    return 0;
}
