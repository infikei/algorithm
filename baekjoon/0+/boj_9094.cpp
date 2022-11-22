#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M, cnt = 0;
        cin >> N >> M;

        for (int a = 1; a < N; a++) {
            int tmp = a * a + M;
            for (int b = a + 1; b < N; b++) {
                if ((b * b + tmp) % (a * b) == 0) {
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}