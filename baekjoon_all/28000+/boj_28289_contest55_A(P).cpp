// Solve 2023-07-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int cnt[4];

int main() {
    FASTIO;

    int p;
    cin >> p;

    for (int i = 0; i < p; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) cnt[3]++;
        else if (b <= 2) cnt[0]++;
        else if (b == 3) cnt[1]++;
        else cnt[2]++;
    }

    for (int i = 0; i < 4; i++) {
        cout << cnt[i] << '\n';
    }

    return 0;
}
