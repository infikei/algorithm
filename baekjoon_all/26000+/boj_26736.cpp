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

    string goals;
    cin >> goals;

    int a = 0, b = 0;

    for (char &c : goals) {
        if (c == 'A') a++;
        else b++;
    }

    cout << a << " : " << b << '\n';

    return 0;
}
