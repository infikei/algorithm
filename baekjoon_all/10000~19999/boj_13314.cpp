#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int N = 100;
    cout << N << '\n';

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) cout << 0 << ' ';
            else if (i == N || j == N) cout << 1 << ' ';
            else cout << 3 << ' ';
        }
        cout << '\n';
    }

    return 0;
}