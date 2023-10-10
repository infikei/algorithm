// Solve 2022-06-07
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

    string word;
    cin >> word;

    int ans = 0;

    for (char &ch : word) {
        int tmp = ch - 'A';

        if (tmp >= 18) tmp--;
        if (tmp >= 24) tmp--;

        ans += tmp / 3 + 3;
    }

    cout << ans << '\n';

    return 0;
}
