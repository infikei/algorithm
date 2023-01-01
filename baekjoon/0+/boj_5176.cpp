#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int P, M, ans;
bool visited[501];

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> P >> M;
        ans = 0;

        for (int i = 1; i <= M; i++) {
            visited[i] = false;
        }

        for (int i = 0; i < P; i++) {
            int x;
            cin >> x;
            if (visited[x]) ans++;
            else visited[x] = true;
        }

        cout << ans << '\n';
    }

    return 0;
}