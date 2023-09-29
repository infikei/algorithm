// Solve 2023-09-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int m = a * b;
    int p = c * d;

    if (m > p) cout << "M\n";
    else if (m < p) cout << "P\n";
    else cout << "E\n";

    return 0;
}
