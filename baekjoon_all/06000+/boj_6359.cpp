#include <iostream>
#include <cmath>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        int ans = floor(sqrt(N));
        cout << ans << '\n';
    }

    return 0;
}