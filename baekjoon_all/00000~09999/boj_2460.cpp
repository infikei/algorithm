#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int cnt = 0, now = 0;

    for (int i = 0; i < 10; i++) {
        int getoff, geton;
        cin >> getoff >> geton;

        now -= getoff;
        now += geton;
        cnt = max(cnt, now);
    }

    cout << cnt << '\n';

    return 0;
}