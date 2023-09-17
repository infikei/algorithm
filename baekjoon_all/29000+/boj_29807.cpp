// Solve 2023-09-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    int score[5] = { 0 };

    for (int i = 0; i < t; i++) {
        cin >> score[i];
    }

    int ans = 0;

    if (score[0] > score[2]) ans += (score[0] - score[2]) * 508;
    else ans += (score[2] - score[0]) * 108;

    if (score[1] > score[3]) ans += (score[1] - score[3]) * 212;
    else ans += (score[3] - score[1]) * 305;

    ans += score[4] * 707;

    ans *= 4763;

    cout << ans << '\n';

    return 0;
}
