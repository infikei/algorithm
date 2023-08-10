// Solve 2022-11-03
// Update 2023-08-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string numbers;
    cin >> numbers;

    if (numbers.substr(0, 3) == "555") {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
