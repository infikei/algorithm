#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

string board[8];
int cnt;

int main() {
    fastio;

    for (int row = 0; row < 8; row++) {
        cin >> board[row];
    }

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if ((row + col) % 2 == 0 && board[row][col] == 'F') {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}