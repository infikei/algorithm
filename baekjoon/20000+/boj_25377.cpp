#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, ans = 7654321;

int main() {
    fastio;

    cin >> N;
    for (int n = 0; n < N; n++) {
        int A, B;
        cin >> A >> B;
        if (A <= B) {
            ans = min(ans, B);
        }
    }

    if (ans == 7654321) {
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}