#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, M, basket[101];

int main() {
    fastio;

    cin >> N >> M;

    int i, j, k;
    for (int m = 0; m < M; m++) {
        cin >> i >> j >> k;
        for (int n = i; n <= j; n++) {
            basket[n] = k;
        }
    }

    for (int n = 1; n <= N; n++) {
        cout << basket[n] << ' ';
    }
    cout << '\n';

    return 0;
}