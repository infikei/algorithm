#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    while (true) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }

        int ans = 1;

        while (N > 0) {
            if (N % 10 == 1) {
                ans += 3;
            }
            else if (N % 10 == 0) {
                ans += 5;
            }
            else {
                ans += 4;
            }

            N /= 10;
        }

        cout << ans << '\n';
    }

    return 0;
}