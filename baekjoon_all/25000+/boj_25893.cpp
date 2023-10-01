// Solve 2023-09-30

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
        if (i >= 1) cout << '\n';

        int a, b, c;
        cin >> a >> b >> c;

        cout << a << ' ' << b << ' ' << c << '\n';

        int cnt = 0;

        if (a >= 10) cnt++;
        if (b >= 10) cnt++;
        if (c >= 10) cnt++;

        if (cnt == 0) cout << "zilch\n";
        else if (cnt == 1) cout << "double\n";
        else if (cnt == 2) cout << "double-double\n";
        else cout << "triple-double\n";
    }

    return 0;
}
