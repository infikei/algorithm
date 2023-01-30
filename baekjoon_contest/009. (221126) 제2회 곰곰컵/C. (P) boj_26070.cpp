#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using uint = unsigned int;

uint gomgom[3], ticket[3], cnt;

int main() {
    fastio;

    for (int i = 0; i < 3; i++) {
        cin >> gomgom[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> ticket[i];
    }

    // 1st chance
    for (int i = 0; i < 3; i++) {
        if (ticket[i] < gomgom[i]) {
            cnt += ticket[i];
            gomgom[i] -= ticket[i];
            ticket[i] = 0;
        }
        else {
            cnt += gomgom[i];
            ticket[i] -= gomgom[i];
            gomgom[i] = 0;
        }
    }

    // 2nd chance
    for (int i = 0; i < 3; i++) {
        if (ticket[i] < 3) {
            continue;
        }
        int ii = (i + 1) % 3;
        if (gomgom[ii] < ticket[i] / 3) {
            cnt += gomgom[ii];
            ticket[i] -= gomgom[ii] * 3;
            gomgom[ii] = 0;
        }
        else {
            int k = ticket[i] / 3;
            cnt += k;
            gomgom[ii] -= k;
            ticket[i] -= k * 3;
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