// Solve 2022-10-26
// Update 2023-09-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    string s[20];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    bool is_increasing = true, is_decreasing = true;

    for (int i = 1; i < n; i++) {
        if (s[i - 1] < s[i]) is_decreasing = false;
        else is_increasing = false;
    }

    if (is_increasing) cout << "INCREASING\n";
    else if (is_decreasing) cout << "DECREASING\n";
    else cout << "NEITHER\n";

    return 0;
}
