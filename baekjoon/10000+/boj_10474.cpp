#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int A, B, Q, R;
    while (true) {
        cin >> A >> B;
        if (A == 0 && B == 0) {
            break;
        }

        Q = A / B;
        R = A % B;
        cout << Q << ' ' << R << " / " << B << '\n';
    }

    return 0;
}