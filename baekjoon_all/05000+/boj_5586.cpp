// Solve 2022-10-16
// Update 2023-08-28

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

    string targets[2] = { "JOI", "IOI" };

    for (int i = 0; i < 2; i++) {
        int cnt = 0;
        int pos = s.find(targets[i]);

        while (pos != string::npos) {
            cnt++;
            pos = s.find(targets[i], pos + 1);
        }

        cout << cnt << '\n';
    }

    return 0;
}
