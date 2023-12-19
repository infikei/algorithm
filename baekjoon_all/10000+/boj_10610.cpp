// Solve 2023-03-13
// Update 2023-12-19

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

    bool is_possible = true;
    int digit_sum = 0;

    for (char d : n) {
        digit_sum += d - '0';
    }

    if (digit_sum % 3 != 0) {
        is_possible = false;
    }

    if (is_possible) {
        sort(n.begin(), n.end(), greater<int>());

        if (n.back() != '0') {
            is_possible = false;
        }
    }

    cout << (is_possible ? n : "-1") << '\n';

    return 0;
}
