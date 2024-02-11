// Solve 2022-07-27
// Update 2023-09-03

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

    priority_queue<int> pq_maxtop;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            if (pq_maxtop.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq_maxtop.top() << '\n';
                pq_maxtop.pop();
            }
        }
        else {
            pq_maxtop.push(x);
        }
    }

    return 0;
}
