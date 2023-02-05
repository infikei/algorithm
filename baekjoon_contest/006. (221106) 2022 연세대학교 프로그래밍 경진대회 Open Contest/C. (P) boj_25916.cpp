#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, M, hole[500000], ans;

int main() {
    fastio;

    cin >> N >> M;
    for (int n = 0; n < N; n++) {
        cin >> hole[n];
    }

    int i = 0, j = 0;
    int now = 0;
    while (i < N) {
        while (now < M && j < N) {
            now += hole[j];
            j++;
            if (now <= M) {
                ans = max(ans, now);
            }
        }

        now -= hole[i];
        i++;
        if (now <= M) {
            ans = max(ans, now);
        }
        if (ans == M) {
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}