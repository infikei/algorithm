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

    int n;
    cin >> n;

    int a_sum = 0, b_sum = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b) a_sum += a + b;
        else if (a < b) b_sum += a + b;
        else {
            a_sum += a;
            b_sum += b;
        }
    }

    cout << a_sum << ' ' << b_sum << '\n';

    return 0;
}
