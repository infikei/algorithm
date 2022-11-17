#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N, T;
    cin >> N >> T;

    int cnt = 0, now = 0;
    bool flag = true;
    for (int n = 0; n < N; n++) {
        int x;
        cin >> x;

        if (flag) {
            if (now + x > T) {
                flag = false;
                continue;
            }

            cnt++;
            now += x;
            if (now == T) {
                flag = false;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}