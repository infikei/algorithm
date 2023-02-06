#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    fastio;

    int numbers[5];
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    int ans = numbers[0] * numbers[1] * numbers[2];

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            int lcm2 = lcm(numbers[i], numbers[j]);
            for (int k = j + 1; k < 5; k++) {
                ans = min(ans, lcm(lcm2, numbers[k]));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}