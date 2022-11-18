#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int R, C;
    cin >> R >> C;

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}