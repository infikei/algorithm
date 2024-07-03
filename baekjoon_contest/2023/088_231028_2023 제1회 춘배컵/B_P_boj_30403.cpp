// Solve 2023-10-28
// Update 2023-12-25

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
    string s;
    cin >> n >> s;

    string rainbow = "roygbivROYGBIV";
    bool check[14] = { false };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 14; j++) {
            if (s[i] == rainbow[j]) {
                check[j] = true;
                break;
            }
        }
    }

    bool lower = true;
    bool upper = true;

    for (int i = 0; i < 7; i++) {
        if (!check[i]) {
            lower = false;
            break;
        }
    }

    for (int i = 7; i < 14; i++) {
        if (!check[i]) {
            upper = false;
            break;
        }
    }

    if (lower) {
        if (upper) {
            cout << "YeS\n";
        }
        else {
            cout << "yes\n";
        }
    }
    else {
        if (upper) {
            cout << "YES\n";
        }
        else {
            cout << "NO!\n";
        }
    }

    return 0;
}
