// Solve 2023-12-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int winning_numbers[6];
    int winning_amount[6];

    for (int i = 0; i < 6; i++) {
        cin >> winning_numbers[i] >> winning_amount[i];
    }

    while (true) {
        int number;
        cin >> number;

        if (number == -1) break;

        int ans = 0;

        if (winning_numbers[0] == number) {
            ans += winning_amount[0];
        }

        if (winning_numbers[1] == number / 1000) {
            ans += winning_amount[1];
        }

        if (winning_numbers[2] == number / 1000) {
            ans += winning_amount[2];
        }

        if (winning_numbers[3] == number % 1000) {
            ans += winning_amount[3];
        }

        if (winning_numbers[4] == number % 1000) {
            ans += winning_amount[4];
        }

        if (winning_numbers[5] == number % 100) {
            ans += winning_amount[5];
        }

        cout << ans << '\n';
    }

    return 0;
}
