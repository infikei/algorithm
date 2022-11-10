#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, F[46] = {0, 1, 1};

int main() {
    fastio;

    cin >> N;

    for (int i = 3; i <= N; i++) {
        F[i] = F[i - 2] + F[i - 1];
    }

    cout << F[N - 1] << ' ' << F[N] << '\n';

    return 0;
}