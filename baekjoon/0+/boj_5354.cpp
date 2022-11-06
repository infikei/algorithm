#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        if (t > 0) {
            cout << '\n';
        }

        int J;
        cin >> J;

        for (int row = 0; row < J; row++) {
            if (row == 0 || row == J - 1) {
                for (int col = 0; col < J; col++) {
                    cout << '#';
                }
            }
            else {
                cout << '#';
                for (int col = 2; col < J; col++) {
                    cout << 'J';
                }
                cout << '#';
            }
            cout << '\n';
        }
    }

    return 0;
}