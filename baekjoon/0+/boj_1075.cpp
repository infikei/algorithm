#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using uint = unsigned int;

int main() {
    fastio;

    uint N, F;
    cin >> N >> F;

    N = N / 100 * 100;
    N += (F - N % F) % F;

    uint ans = N % 100;
    if (ans < 10) {
        cout << '0';
    }
    cout << ans << '\n';

    return 0;
}