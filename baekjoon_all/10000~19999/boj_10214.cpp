#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int Y_sum = 0, K_sum = 0;

        for (int i = 0; i < 9; i++) {
            int Y, K;
            cin >> Y >> K;
            Y_sum += Y;
            K_sum += K;
        }

        if (Y_sum > K_sum) {
            cout << "Yonsei\n";
        }
        else if (Y_sum < K_sum) {
            cout << "Korea\n";
        }
        else {
            cout << "Draw\n";
        }
    }

    return 0;
}