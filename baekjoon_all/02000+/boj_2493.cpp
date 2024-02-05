// Solve 2022-08-06
// Update 2024-02-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Tower{
    int height, idx;

    Tower(int height, int idx) : height(height), idx(idx) {}
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    stack<Tower> stck;

    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;

        while (!stck.empty() && stck.top().height < h) {
            stck.pop();
        }

        cout << (stck.empty() ? 0 : stck.top().idx) << ' ';
        stck.emplace(h, i);
    }

    cout << '\n';

    return 0;
}
