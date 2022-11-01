#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int S, T, D;
    cin >> S >> T >> D;

    int F = D / (2 * S) * T;
    cout << F << '\n';

    return 0;
}