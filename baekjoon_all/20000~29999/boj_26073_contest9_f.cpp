#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    fastio;

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int X, Y;
        cin >> X >> Y;

        int K, A, gcd_of_A;
        cin >> K >> gcd_of_A;
        for (int k = 1; k < K; k++) {
            cin >> A;
            gcd_of_A = gcd(A, gcd_of_A);
        }

        if (X % gcd_of_A == 0 && Y % gcd_of_A == 0) {
            cout << "Ta-da\n";
        }
        else {
            cout << "Gave up\n";
        }
    }

    return 0;
}