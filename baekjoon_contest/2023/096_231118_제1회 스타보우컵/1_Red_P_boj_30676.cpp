// Solve 2023-11-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int lambda;
    cin >> lambda;

    if (lambda >= 620) cout << "Red\n";
    else if (lambda >= 590) cout << "Orange\n";
    else if (lambda >= 570) cout << "Yellow\n";
    else if (lambda >= 495) cout << "Green\n";
    else if (lambda >= 450) cout << "Blue\n";
    else if (lambda >= 425) cout << "Indigo\n";
    else cout << "Violet\n";

    return 0;
}
