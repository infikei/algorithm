#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int sum, diff;
    cin >> sum >> diff;

    int ans[2];
    ans[0] = (sum + diff) / 2;
    ans[1] = (sum - diff) / 2;

    if (ans[0] < 0 || ans[1] < 0) {
        cout << -1 << '\n';
    }
    else if (ans[0] + ans[1] != sum || ans[0] - ans[1] != diff) {
        cout << -1 << '\n';
    }
    else {
        cout << ans[0] << ' ' << ans[1] << '\n';
    }

    return 0;
}