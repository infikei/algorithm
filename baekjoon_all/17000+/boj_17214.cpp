// Solve 2023-07-31

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    cin >> s;

    int idx = s.find('x');
    int co[2] = { 0, 0 };

    if (idx == string::npos) {
        co[1] = stoi(s);
    }
    else {
        string s0 = s.substr(0, idx);
        co[0] = stoi(s0);

        string s1 = s.substr(idx + 1, SIZE(s) - idx - 1);
        if (!s1.empty()) {
            co[1] = stoi(s1);
        }
    }

    co[0] /= 2;

    string ans;

    if (co[0] != 0) {
        if (co[0] == 1) ans += "xx+";
        else if (co[0] == -1) ans += "-xx+";
        else ans += to_string(co[0]) + "xx+";
    }

    if (co[1] != 0) {
        if (co[1] < 0 && !ans.empty()) {
            ans.pop_back();
        }

        if (co[1] == 1) ans += "x+";
        else if (co[1] == -1) ans += "-x+";
        else ans += to_string(co[1]) + "x+";
    }

    ans += "W";

    cout << ans << '\n';

    return 0;
}
