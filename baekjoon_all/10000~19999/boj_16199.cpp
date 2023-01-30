#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int yymmdd[6];
    for (int i = 0; i < 6; i++) {
        cin >> yymmdd[i];
    }

    int ans[3];

    ans[2] = yymmdd[3] - yymmdd[0];

    ans[1] = ans[2] + 1;

    ans[0] = ans[2];
    if (100 * yymmdd[4] + yymmdd[5] < 100 * yymmdd[1] + yymmdd[2]) {
        ans[0]--;
    }

    for (int i = 0; i < 3; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}