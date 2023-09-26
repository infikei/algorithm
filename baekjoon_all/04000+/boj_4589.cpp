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

    int n;
    cin >> n;

    cout << "Gnomes:\n";

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a < b && b < c || a > b && b > c) cout << "Ordered\n";
        else cout << "Unordered\n";
    }

    return 0;
}
