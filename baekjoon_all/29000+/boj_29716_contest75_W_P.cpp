// Solve 2023-09-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int j, n;
    cin >> j >> n;
    cin.ignore();

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        int val = 0;

        for (char c : s) {
            if (c >= 'A' && c <= 'Z') val += 4;
            else if (c >= 'a' && c <= 'z') val += 2;
            else if (c >= '0' && c <= '9') val += 2;
            else val++;
        }

        if (val <= j) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
