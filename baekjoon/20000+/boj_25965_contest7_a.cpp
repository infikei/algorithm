#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

int player[3];
int mission[100][3];
ll ans;

int main() {
    fastio;

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int M;
        cin >> M;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> mission[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            cin >> player[i];
        }

        ans = 0;
        for (int i = 0; i < M; i++) {
            ll now = player[0] * (ll)mission[i][0] - player[1] * (ll)mission[i][1] + player[2] * (ll)mission[i][2];
            if (now > 0) {
                ans += now;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}