// Solve 2022-09-09
// Update 2023-09-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Num{
    int val, pop;
    Num(int x = 0, int t = 0) : val(x), pop(t) {}
};

int main() {
    FASTIO;

    int n, l;
    cin >> n >> l;

    deque<Num> dque;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (!dque.empty() && dque.front().pop <= i) {
            dque.pop_front();
        }

        while (!dque.empty() && dque.back().val >= x) {
            dque.pop_back();
        }

        dque.emplace_back(x, i + l);

        cout << dque.front().val << ' ';
    }

    cout << '\n';

    return 0;
}
