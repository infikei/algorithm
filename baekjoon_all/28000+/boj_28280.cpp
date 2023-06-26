// Solve 2023-06-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

bool visited[4000001];

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int k;
        cin >> k;

        if (k == 1) {
            cout << 0 << '\n';
            continue;
        }

        for (int i = 1; i < 4000001; i++) {
            visited[i] = false;
        }
        visited[0] = true;

        queue<int> que;
        que.push(1);
        visited[1] = true;
        int ans = 0;

        while (true) {
            ans++;
            bool flag = false;

            for (int i = 0, i_end = SIZE(que); i < i_end; i++) {
                int cur = que.front();
                que.pop();

                int next = cur << 1;
                if (next == k) {
                    flag = true;
                    break;
                }
                if (next < 4000001 && !visited[next]) {
                    visited[next] = true;
                    que.push(next);
                }

                next = cur - 1;
                if (next == k) {
                    flag = true;
                    break;
                }
                if (!visited[next]) {
                    visited[next] = true;
                    que.push(next);
                }
            }

            if (flag) break;
        }

        cout << ans << '\n';
    }

    return 0;
}
