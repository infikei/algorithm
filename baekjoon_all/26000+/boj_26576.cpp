// Solve 2023-08-22
// Update 2023-09-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;

unordered_map<string, int> hs = {
    { "January", 1 },
    { "February", 2 },
    { "March", 3 },
    { "April", 4 },
    { "May", 5 },
    { "June", 6 },
    { "July", 7 },
    { "August", 8 },
    { "September", 9 },
    { "October", 10 },
    { "November", 11 },
    { "December", 12 }
};

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string s[3];

        for (int i = 0; i < 3; i++) {
            cin >> s[i];
        }

        int ans_month = -1;

        if (hs.find(s[0]) != hs.end()) {
            ans_month = hs[s[0]];
        }

        int ans_day = stoi(s[1].substr(0, SIZE(s[1]) - 1));
        int ans_year = stoi(s[2]) % 100;

        if (ans_month == -1 || ans_day < 1 || ans_day > 31) {
            cout << "Invalid\n";
        }
        else {
            cout << setfill('0') << setw(2) << ans_month << '/';
            cout << setfill('0') << setw(2) << ans_day << '/';
            cout << setfill('0') << setw(2) << ans_year << '\n';
        }
    }

    return 0;
}
