// Solve 2024-02-02

#include <iostream>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp

int main() {
    FASTIO;

    int n;
    unsigned int bitset[(1 << 20)] = { 0 };

    while (cin >> n) {
        --n;

        if ((bitset[n >> 5] & (1u << (n & 31))) == 0) {
            bitset[n >> 5] |= (1u << (n & 31));
            cout << ++n << ' ';
        }
    }

    cout << '\n';

    return 0;
}
