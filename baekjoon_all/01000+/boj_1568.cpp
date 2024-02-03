// Solve 2022-10-11
// Update 2024-02-02

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

    int cnt = 0;
    int i = 1;

    while (n > 0) {
        n -= i;
        i++;
        cnt++;

        if (n - i < 0) {
            i = 1;
        }
    }

    cout << cnt << '\n';

    return 0;
}
