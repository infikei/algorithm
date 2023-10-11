// Solve 2022-12-15
// Update 2023-10-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    priority_queue<int> present_box;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;

        present_box.push(c);
    }

    bool check = true;

    for (int i = 0; i < m; i++) {
        int w;
        cin >> w;

        if (check) {
            if (w > present_box.top()) {
                check = false;
            }
            else {
                w = present_box.top() - w;
                present_box.pop();
                present_box.push(w);
            }
        }
    }

    cout << check << '\n';

    return 0;
}
