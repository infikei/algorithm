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

    string today;
    int n;
    cin >> today >> n;

    int yyyy = stoi(today.substr(0, 4));
    int mm = stoi(today.substr(5, 2));
    int dd = stoi(today.substr(8, 2));

    dd += n;

    mm += (dd - 1) / 30;
    dd = (dd - 1) % 30 + 1;

    yyyy += (mm - 1) / 12;
    mm = (mm - 1) % 12 + 1;

    cout << yyyy << '-';

    if (mm < 10) cout << 0 << mm << '-';
    else cout << mm << '-';

    if (dd < 10) cout << 0 << dd << '\n';
    else cout << dd << '\n';

    return 0;
}
