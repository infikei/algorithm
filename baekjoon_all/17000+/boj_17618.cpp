#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, cnt;

int main() {
    fastio;

    cin >> N;

    for (int n = 1; n <= N; n++) {
        int n2 = n, n3 = 0;
        while (n2 > 0) {
            n3 += n2 % 10;
            n2 /= 10;
        }
        if (n % n3 == 0) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}