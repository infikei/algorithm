#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int calc_1292(int x) {
    int res = 0;

    int now = 0, i = 1;
    while (true) {
        if (now + i <= x) {
            res += i * i;
            now += i;
            i++;
        }
        else {
            res += i * (x - now);
            break;
        }
    }

    return res;
}

int main() {
    fastio;

    int A, B;
    cin >> A >> B;

    cout << calc_1292(B) - calc_1292(A - 1) << '\n';

    return 0;
}