#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int calc_sum(int k, int mod) {
    int res = 0;
    while (k > 0) {
        res += k % mod;
        k /= mod;
    }
    return res;
}

int main() {
    fastio;

    for (int n = 1000; n < 10000; n++) {
        int sum10 = calc_sum(n, 10);
        int sum12 = calc_sum(n, 12);
        if (sum10 != sum12) continue;
        int sum16 = calc_sum(n, 16);
        if (sum10 != sum16) continue;
        cout << n << '\n';
    }

    return 0;
}