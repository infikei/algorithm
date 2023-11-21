// Solve 2022-12-05
// Update 2023-11-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    queue<int> que;

    while (true) {
        int packet;
        cin >> packet;

        if (packet == -1) break;

        if (packet == 0) {
            que.pop();
            continue;
        }

        if (SIZE(que) < n) {
            que.push(packet);
        }
    }

    if (que.empty()) {
        cout << "empty\n";
    }
    else {
        while (!que.empty()) {
            cout << que.front() << ' ';
            que.pop();
        }
    }

    return 0;
}
