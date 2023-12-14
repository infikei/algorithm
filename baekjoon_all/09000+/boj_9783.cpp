// Solve 2023-12-14

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
    getline(cin, s);

    string ans;

    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            int x = c - 'a' + 1;

            ans.push_back('0' + x / 10);
            ans.push_back('0' + x % 10);
        }
        else if (c >= 'A' && c <= 'Z') {
            int x = c - 'A' + 27;

            ans.push_back('0' + x / 10);
            ans.push_back('0' + x % 10);
        }
        else if (c >= '0' && c <= '9') {
            ans.push_back('#');
            ans.push_back(c);
        }
        else {
            ans.push_back(c);
        }
    }

    cout << ans << '\n';

    return 0;
}
