// Solve 2023-09-10
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string today;
    int n;
    cin >> today >> n;

    int ans_year = stoi(today.substr(0, 4));
    int ans_month = stoi(today.substr(5, 2));
    int ans_day = stoi(today.substr(8, 2));

    ans_day += n;

    ans_month += (ans_day - 1) / 30;
    ans_day = (ans_day - 1) % 30 + 1;

    ans_year += (ans_month - 1) / 12;
    ans_month = (ans_month - 1) % 12 + 1;

    cout << ans_year << '-';
    cout << setfill('0') << setw(2) << ans_month << '-';
    cout << setfill('0') << setw(2) << ans_day << '\n';

    return 0;
}
