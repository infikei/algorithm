// Solve 2022-08-01
// Update 2023-08-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k, m;
    cin >> n >> k >> m;

    deque<int> dq;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    int mi = 0;
    bool dq_direction = true;

    while (!dq.empty()) {
        if (dq_direction) {
            for (int ki = 1; ki < k; ki++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }

            cout << dq.front() << '\n';
            dq.pop_front();

            mi++;

            if (mi == m) {
                dq_direction = false;
                mi = 0;
            }
        }
        else {
            for (int ki = 1; ki < k; ki++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }

            cout << dq.back() << '\n';
            dq.pop_back();

            mi++;

            if (mi == m) {
                dq_direction = true;
                mi = 0;
            }
        }
    }

    return 0;
}
