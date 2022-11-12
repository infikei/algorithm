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

        int i = 0;
        while (N > 0) {
            if (N % 2 == 1) {
                cout << i << ' ';
            }
            N = N / 2;
            i++;
        }

        cout << '\n';
    }

    return 0;
}