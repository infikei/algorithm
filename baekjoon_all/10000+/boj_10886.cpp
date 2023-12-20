// Solve 2022-10-23
// Update 2023-12-20

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

    int cnt[2] = { 0 };

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cnt[x]++;
    }

    cout << (cnt[0] > cnt[1] ? "Junhee is not cute!" : "Junhee is cute!") << '\n';

    return 0;
}
