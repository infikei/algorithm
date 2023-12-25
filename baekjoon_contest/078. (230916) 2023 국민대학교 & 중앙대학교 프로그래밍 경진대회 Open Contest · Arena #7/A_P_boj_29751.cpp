// Solve 2023-09-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int w, h;
    cin >> w >> h;

    double area = w * h * 0.5;

    SETPRECISION(1);

    cout << area << '\n';

    return 0;
}
