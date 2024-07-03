// Solve 2022-11-26
// Update 2023-09-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;

int main() {
    FASTIO;

    uint gomgom[3], ticket[3], cnt = 0;

    for (int i = 0; i < 3; i++) {
        cin >> gomgom[i];
    }

    for (int i = 0; i < 3; i++) {
        cin >> ticket[i];
    }

    // 1st chance

    for (int i = 0; i < 3; i++) {
        if (gomgom[i] <= ticket[i]) {
            cnt += gomgom[i];
            ticket[i] -= gomgom[i];
            gomgom[i] = 0;
        }
        else {
            cnt += ticket[i];
            gomgom[i] -= ticket[i];
            ticket[i] = 0;
        }
    }

    // 2nd chance

    for (int i = 0; i < 3; i++) {
        if (ticket[i] < 3) continue;

        int ii = (i + 1) % 3;

        if (gomgom[ii] <= ticket[i] / 3) {
            cnt += gomgom[ii];
            ticket[i] -= gomgom[ii] * 3;
            gomgom[ii] = 0;
        }
        else {
            uint t3 = ticket[i] / 3;
            cnt += t3;
            gomgom[ii] -= t3;
            ticket[i] -= t3 * 3;
        }
    }

    // last chance

    for (int i = 0; i < 3; i++) {
        int ii = (i + 1) % 3, iii = (i + 2) % 3;

        if (gomgom[i] == 0 && gomgom[ii] == 0 && gomgom[iii] > 0) {
            uint t = (ticket[i] / 3 + ticket[ii]) / 3;
            cnt += min(t, gomgom[iii]);
        }
    }

    cout << cnt << '\n';

    return 0;
}
