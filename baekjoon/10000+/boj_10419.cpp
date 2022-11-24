#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int D;
        cin >> D;

        int ans = 1;
        while (true) {
            if (D < ans * (ans + 1)) {
                ans--;
                break;
            }
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}