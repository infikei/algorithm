// Solve 2023-12-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int weights[7] = { 2, 7, 6, 5, 4, 3, 2 };
    string result_letters = "JABCDEFGHIZ";

    string digits;
    cin >> digits;

    int sum = 0;

    for (int i = 0; i < 7; i++) {
        sum += weights[i] * (digits[i] - '0');
    }

    sum %= 11;

    cout << result_letters[sum] << '\n';

    return 0;
}
