// Solve 2023-09-10
// Update 2023-09-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s_str, e_str;
    int n, t;
    cin >> s_str >> e_str >> n >> t;

    int s = stoi(s_str.substr(0, 2)) * 60 + stoi(s_str.substr(3, 2));
    int e = stoi(e_str.substr(0, 2)) * 60 + stoi(e_str.substr(3, 2));

    int today_max = (e - s - 1) / t;

    int ans = n / today_max;

    int ans2 = s + t * (n % today_max + 1);
    int ans2_hour = ans2 / 60;
    int ans2_min = ans2 % 60;

    cout << ans << '\n';
    cout << setfill('0') << setw(2) << ans2_hour << ':';
    cout << setfill('0') << setw(2) << ans2_min << '\n';

    return 0;
}
