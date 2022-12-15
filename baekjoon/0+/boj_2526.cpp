#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, P, ans;

int main() {
    fastio;

    cin >> N >> P;
    vector<int> visited(P, 0);

    int now = N, cnt = 1;
    if (now < P) {
        visited[now] = cnt;
    }

    while (true) {
        now = now * N % P;
        cnt++;
        if (visited[now] > 0) {
            ans = cnt - visited[now];
            break;
        }
        visited[now] = cnt;
    }

    cout << ans << '\n';

    return 0;
}