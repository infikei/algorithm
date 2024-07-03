// Solve 2022-11-26
// Update 2023-08-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string d_day;
        cin >> d_day;

        int d = stoi(d_day.substr(2, SIZE(d_day) - 2));

        if (d < 91) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
