#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int N, K, coupon, stamp, chicken;

    while (cin >> N) {
        cin >> K;

        coupon = N, stamp = 0, chicken = 0;
        while (true) {
            stamp += coupon;
            chicken += coupon;
            coupon = stamp / K;
            stamp %= K;
            if (coupon == 0 && stamp < K) {
                break;
            }
        }

        cout << chicken << '\n';
    }

    return 0;
}