// Solve 2023-08-22 (BOJ First Solved)

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (s == "") getline(cin, s);

        stringstream ss(s);
        getline(ss, s, ':');
        int a = stoi(s);
        getline(ss, s, ':');
        int b = stoi(s);

        int cnt = 0;

        for (int c = 0; c < 10; c++) {
            for (int d = 0; d < 10; d++) {
                if (a + c > b + d) cnt++;
                else if (a + c == b + d && c > b) cnt++;
            }
        }

        cout << cnt << ' ' << 99 - cnt << '\n';
    }

    return 0;
}
