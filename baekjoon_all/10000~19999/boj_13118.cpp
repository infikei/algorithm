#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int people[4];
    for (int i = 0; i < 4; i++) {
        cin >> people[i];
    }
    int x, y, r;
    cin >> x >> y >> r;

    int ans = 0;

    for (int i = 0; i < 4; i++) {
        if (people[i] == x) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}