#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    N = (N - 1) % 8 + 1;
    if (N >= 6) {
        N = 10 - N;
    }

    cout << N << '\n';

    return 0;
}