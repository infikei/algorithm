#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int C, cnt;

int main() {
    fastio;

    cin >> C;

    while (true) {
        cnt++;
        if (C == 1) {
            break;
        }
        if (C % 2 == 0) {
            C /= 2;
        }
        else {
            C *= 3;
            C += 1;
        }
    }

    cout << cnt << '\n';

    return 0;
}