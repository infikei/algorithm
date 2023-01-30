#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int D, H, M;
    cin >> D >> H >> M;

    int starting = (11 * 24 + 11) * 60 + 11;
    int ending = (D * 24 + H) * 60 + M;

    if (ending < starting) {
        cout << -1 << '\n';
    }
    else {
        cout << ending - starting << '\n';
    }

    return 0;
}