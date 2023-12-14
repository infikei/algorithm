// Solve 2022-11-22
// Update 2023-12-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int k, n;
    cin >> k >> n;

    int now_time = 0;
    int now_person = k;
    int bomb_person = -1;

    for (int i = 0; i < n; i++) {
        int t;
        char z;
        cin >> t >> z;

        if (bomb_person > 0) continue;

        now_time += t;

        if (now_time >= 210) {
            bomb_person = now_person;
            continue;
        }

        if (z == 'T') {
            now_person = now_person % 8 + 1;
        }
    }

    cout << bomb_person << '\n';

    return 0;
}
