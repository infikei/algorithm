#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int K;
        cin >> K;
        cout << (1 << K) - 1 << '\n';
    }

    return 0;
}