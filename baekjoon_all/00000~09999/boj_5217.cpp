#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        cout << "Pairs for " << N << ':';
        if (N < 3) {
            cout << '\n';
            continue;
        }
        cout << ' ' << 1 << ' ' << N - 1;
        int i_end = (N + 1) / 2;
        for (int i = 2; i < i_end; i++) {
            cout << ", " << i << ' ' << N - i;
        }
        cout << '\n';
    }

    return 0;
}