#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    for (int row = 1; row <= N; row++) {
        for (int i = 0; i < N - row; i++) {
            cout << ' ';
        }
        cout << '*';
        if (row == 1) {
            cout << '\n';
            continue;
        }
        for (int i = 0; i < 2 * row - 3; i++) {
            cout << ' ';
        }
        cout << '*' << '\n';
    }

    return 0;
}