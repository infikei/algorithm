#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int A, B, C;
    cin >> A >> B >> C;

    A += B;
    if (A < C * 2) {
        cout << A << '\n';
    }
    else {
        cout << A - C * 2 << '\n';
    }

    return 0;
}