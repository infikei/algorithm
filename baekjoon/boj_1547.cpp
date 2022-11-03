#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int M, now;

int main() {
    fastio;

    cin >> M;
    now = 1;

    for (int m = 0; m < M; m++) {
        int x, y;
        cin >> x >> y;

        if (x == now) {
            now = y;
        }
        else if (y == now) {
            now = x;
        }
    }

    cout << now << '\n';

    return 0;
}