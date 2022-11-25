#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ull = unsigned long long;

int main() {
    fastio;

    int X[2], Y[2], R[2];
    for (int i = 0; i < 2; i++) {
        cin >> X[i] >> Y[i] >> R[i];
    }

    ull X_diff = abs(X[1] - X[0]);
    ull Y_diff = abs(Y[1] - Y[0]);
    ull R_sum = R[0] + R[1];
    if (X_diff * X_diff + Y_diff * Y_diff < R_sum * R_sum) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}