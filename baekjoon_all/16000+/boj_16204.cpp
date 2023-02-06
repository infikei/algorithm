#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N, M, K;
    cin >> N >> M >> K;

    cout << min(M, K) + min(N - M, N - K) << '\n';

    return 0;
}