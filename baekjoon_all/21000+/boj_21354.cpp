// Solve 2023-09-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int apple, pear;
    cin >> apple >> pear;

    apple *= 7;
    pear *= 13;

    if (apple > pear) cout << "Axel\n";
    else if (apple < pear) cout << "Petra\n";
    else cout << "lika\n";

    return 0;
}
