// Solve 2023-08-22

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

        int m = -1;
        if (hs.find(s[0]) != hs.end()) {
            m = hs[s[0]];
        }
        int d = stoi(s[1].substr(0, SIZE(s[1]) - 1));
        int y = stoi(s[2]) % 100;

        if (m == -1 || d < 1 || d > 31) cout << "Invalid\n";
        else {
            if (m < 10) cout << 0 << m;
            else cout << m;

            if (d < 10) cout << "/0" << d;
            else cout << '/' << d;

            if (y < 10) cout << "/0" << y << '\n';
            else cout << '/' << y << '\n';
        }
    }

    return 0;
}
