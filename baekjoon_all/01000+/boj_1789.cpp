#include <iostream>
#include <cmath>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ull = unsigned long long;

int main() {
    fastio;

    ull S;
    cin >> S;

    ull N = sqrt(S * 2);
    while (true) {
        if (N * (N + 1) / 2 > S) {
            N--;
            break;
        }
        N++;
    }

    cout << N << '\n';

    return 0;
}