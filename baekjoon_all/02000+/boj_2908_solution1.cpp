// Solve 2022-06-07
// Update 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string a, b;
    cin >> a >> b;

    for (int i = 2; i >= 0; i--) {
        if (a[i] > b[i]) {
            cout << a[2] << a[1] << a[0] << '\n';
            break;
        }
        else if (a[i] < b[i]) {
            cout << b[2] << b[1] << b[0] << '\n';
            break;
        }
    }

    return 0;
}
