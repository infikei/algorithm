#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int MAX_N = 100000;
int n, k, ans[MAX_N + 1], cnt[MAX_N + 1];

void solve() {
    if (n == k) {
        cnt[k]++;
        return;
    }

    for (int i = 0; i <= MAX_N; i++) {
        ans[i] = -1;
    }

    queue<int> q;
    q.push(n);
    ans[n] = 0;
    cnt[n] = 1;

    int now_time = 0;

    while (!q.empty()) {
        now_time++;

        int i_end = q.size();
        for (int i = 0; i < i_end; i++) {
            int now = q.front();
            q.pop();

            int next = now - 1;
            if (next >= 0) {
                if (ans[next] == -1) {
                    q.push(next);
                    ans[next] = now_time;
                }
                if (ans[next] == now_time) {
                    cnt[next] += cnt[now];
                }
            }

            next = now + 1;
            if (next <= MAX_N) {
                if (ans[next] == -1) {
                    q.push(next);
                    ans[next] = now_time;
                }
                if (ans[next] == now_time) {
                    cnt[next] += cnt[now];
                }
            }

            next = now * 2;
            if (next <= MAX_N) {
                if (ans[next] == -1) {
                    q.push(next);
                    ans[next] = now_time;
                }
                if (ans[next] == now_time) {
                    cnt[next] += cnt[now];
                }
            }
        }

        if (cnt[k] > 0) return;
    }
}

int main() {
    fastio;

    cin >> n >> k;

    solve();

    cout << ans[k] << '\n';
    cout << cnt[k] << '\n';

    return 0;
}