#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ll length[3];
        for (int i = 0; i < 3; i++) {
            cin >> length[i];
        }
        sort(length, length + 3);

        length[0] += length[1];
        ll ans = length[0] * length[0] + length[2] * length[2];
        cout << ans << '\n';
    }

    return 0;
}