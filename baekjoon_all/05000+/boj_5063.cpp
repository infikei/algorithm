#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int r, e, c;
        cin >> r >> e >> c;

        if (r < e - c) {
            cout << "advertise\n";
        }
        else if (r > e - c) {
            cout << "do not advertise\n";
        }
        else {
            cout << "does not matter\n";
        }
    }

    return 0;
}