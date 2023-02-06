#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    int cnt = 0;

    int i = 1, i10 = 10, K = N;
    while (K > 0) {
        cnt += (N / i10) * 3 * i;
        cnt += min(max(0, N % i10 - 3 * i + 1), i);
        cnt += min(max(0, N % i10 - 6 * i + 1), i);
        cnt += min(max(0, N % i10 - 9 * i + 1), i);

        i *= 10;
        i10 *= 10;
        K /= 10;
    }

    cout << cnt << '\n';

    return 0;
}