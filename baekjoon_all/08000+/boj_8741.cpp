#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int K;
    cin >> K;

    for (int i = 0; i < K; i++) cout << 1;
    for (int i = 1; i < K; i++) cout << 0;
    cout << '\n';

    return 0;
}