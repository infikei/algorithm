#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int stats[4];
        for (int i = 0; i < 4; i++) {
            cin >> stats[i];
        }
        for (int i = 0; i < 4; i++) {
            int x;
            cin >> x;
            stats[i] += x;
        }

        int ans = max(1, stats[0]) + 5 * max(1, stats[1]);
        ans += 2 * max(0, stats[2]) + 2 * stats[3];
        cout << ans << '\n';
    }

    return 0;
}