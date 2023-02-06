#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int K, N;
    cin >> K >> N;

    int now_time = 0, now_person = K, ans_person = 0;
    for (int n = 0; n < N; n++) {
        int T;
        char Z;
        cin >> T >> Z;

        if (ans_person != 0) {
            continue;
        }

        now_time += T;
        if (now_time >= 210) {
            ans_person = now_person;
            continue;
        }
        if (Z == 'T') {
            now_person = now_person % 8 + 1;
        }
    }

    cout << ans_person << '\n';

    return 0;
}