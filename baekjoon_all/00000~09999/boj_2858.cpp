#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int L, W, R, B;

int main() {
    fastio;

    cin >> R >> B;

    for (int i = 1; i <= B; i++) {
        if (B % i != 0) {
            continue;
        }
        L = B / i + 2;
        W = i + 2;
        if (L * W == R + B) {
            break;
        }
    }

    cout << L << ' ' << W << '\n';

    return 0;
}