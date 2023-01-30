#include <iostream>
using namespace std;

int main() {
    int n;
    int DP[41] = {0};
    DP[1] = 1;
    DP[2] = 1;
    for (int i = 3; i < 41; i++) {
        DP[i] = DP[i - 1] + DP[i - 2];
    }

    cin >> n;
    cout << DP[n] << ' ' << (n - 2) << '\n';

    return 0;
}