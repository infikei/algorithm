#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N, W, H;
    cin >> N >> W >> H;

    int D2 = W * W + H * H;

    for (int n = 0; n < N; n++) {
        int i;
        cin >> i;

        if (i * i <= D2) {
            cout << "DA\n";
        }
        else {
            cout << "NE\n";
        }
    }

    return 0;
}