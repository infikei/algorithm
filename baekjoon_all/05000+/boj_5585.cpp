#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int money[6] = {500, 100, 50, 10, 5, 1};

int main() {
    fastio;

    int K;
    cin >> K;
    K = 1000 - K;

    int cnt = 0;

    for (int i = 0; i < 6; i++) {
        cnt += K / money[i];
        K = K % money[i];
    }

    cout << cnt << '\n';

    return 0;
}