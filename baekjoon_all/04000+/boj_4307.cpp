#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int length, n;
        cin >> length >> n;

        int ans_min = 0, ans_max = 0;
        for (int i = 0; i < n; i++) {
            int pos;
            cin >> pos;
            ans_min = max(ans_min, min(pos, length - pos));
            ans_max = max(ans_max, max(pos, length - pos));
        }
        cout << ans_min << ' ' << ans_max << '\n';
    }

    return 0;
}