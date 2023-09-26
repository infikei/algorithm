// Solve 2023-09-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int hh, mm, ss;
    char c;

    cin >> hh >> c >> mm >> c >> ss;
    int t_s = hh * 3600 + mm * 60 + ss;

    cin >> hh >> c >> mm >> c >> ss;
    int t_e = hh * 3600 + mm * 60 + ss;

    int dt = t_e - t_s;
    if (dt < 0) dt += 86400;

    cout << dt << '\n';

    return 0;
}
