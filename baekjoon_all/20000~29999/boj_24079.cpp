#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int X, Y, Z;
    cin >> X >> Y >> Z;

    if (X + Y > Z) {
        cout << 0 << '\n';
    }
    else {
        cout << 1 << '\n';
    }

    return 0;
}