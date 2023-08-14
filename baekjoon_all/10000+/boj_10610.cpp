// Solve 2023-03-13
// Update 2023-08-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string n;
    cin >> n;

    bool check = true;
    int tmp = 0;

    for (const char c : n) {
        tmp += c - '0';
    }

    if (tmp % 3 != 0) {
        check = false;
    }

    if (check) {
        sort(n.begin(), n.end(), greater<int>());

        if (n.back() != '0') {
            check = false;
        }
    }

    if (check) {
        cout << n << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
