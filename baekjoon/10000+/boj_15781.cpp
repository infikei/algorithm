#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int cnt[2], max_val[2], ans;

int main() {
    fastio;

    for (int i = 0; i < 2; i++) {
        cin >> cnt[i];
    }

    for (int i = 0; i < 2; i++) {
        int j_end = cnt[i];
        for (int j = 0; j < j_end; j++) {
            int x;
            cin >> x;
            max_val[i] = max(max_val[i], x);
        }
        ans += max_val[i];
    }

    cout << ans << '\n';

    return 0;
}