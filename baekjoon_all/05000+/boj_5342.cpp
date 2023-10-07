// Solve 2023-10-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    double ans = 0;

    while (true) {
        string item;
        cin >> item;

        if (item == "Paper") ans += 57.99;
        else if (item == "Printer") ans += 120.50;
        else if (item == "Planners") ans += 31.25;
        else if (item == "Binders") ans += 22.50;
        else if (item == "Calendar") ans += 10.95;
        else if (item == "Notebooks") ans += 11.20;
        else if (item == "Ink") ans += 66.95;
        else break;
    }

    SETPRECISION(2);

    cout << '$' << ans << '\n';

    return 0;
}
