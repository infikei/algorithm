// Solve 2023-07-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int cat[5000];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> cat[i];
    }

    sort(cat, cat + n);

    int ans = 0, i = 0, j = n - 1;

    while (i < j) {
        if (cat[i] + cat[j] <= k) {
            i++;
            j--;
            ans++;
        }
        else {
            j--;
        }
    }

    cout << ans << '\n';

    return 0;
}
