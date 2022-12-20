#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int A[10001];

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }

        int now = 1, next, ans = 1;
        while (true) {
            next = A[now];
            if (next == N) {
                break;
            }
            if (next == 0) {
                ans = 0;
                break;
            }
            A[now] = 0;
            now = next;
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}