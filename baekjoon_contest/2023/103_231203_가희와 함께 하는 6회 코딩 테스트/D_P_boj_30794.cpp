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

    int lv;
    string judge;
    cin >> lv >> judge;

    if (judge == "perfect") {
        cout << lv * 1000 << '\n';
    }
    else if (judge == "great") {
        cout << lv * 600 << '\n';
    }
    else if (judge == "cool") {
        cout << lv * 400 << '\n';
    }
    else if (judge == "bad") {
        cout << lv * 200 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}
