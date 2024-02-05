// Solve 2022-09-09
// Update 2024-02-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Num{
    int num, idx;

    Num(int num, int idx) : num(num), idx(idx) {}
};

int main() {
    FASTIO;

    int n, l;
    cin >> n >> l;

    deque<Num> dque;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (!dque.empty() && dque.front().idx == i - l) {
            dque.pop_front();
        }

        while (!dque.empty() && dque.back().num >= x) {
            dque.pop_back();
        }

        dque.emplace_back(x, i);
        cout << dque.front().num << ' ';
    }

    cout << '\n';

    return 0;
}
