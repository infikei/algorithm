// Solve 2023-08-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    char c;
    cin >> c;

    if (c == 'M') cout << "MatKor\n";
    else if (c == 'W') cout << "WiCys\n";
    else if (c == 'C') cout << "CyKor\n";
    else if (c == 'A') cout << "AlKor\n";
    else cout << "$clear\n";

    return 0;
}
