// Solve 2022-12-27
// Update 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int baskets[101] = { 0 };

    for (int mi = 0; mi < m; mi++) {
        int left, right, num;
        cin >> left >> right >> num;

        for (int i = left; i <= right; i++) {
            baskets[i] = num;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << baskets[i] << ' ';
    }

    cout << '\n';

    return 0;
}
