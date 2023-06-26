// Solve 2022-07-28
// Update 2023-06-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct cmp_abs{
    bool operator()(const int a, const int b) {
        if (abs(a) == abs(b)) return a > b;

        return abs(a) > abs(b);
    }
};

priority_queue<int, vector<int>, cmp_abs> pq_abs_mintop;

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            if (pq_abs_mintop.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq_abs_mintop.top() << '\n';
                pq_abs_mintop.pop();
            }
        }
        else {
            pq_abs_mintop.push(x);
        }
    }

    return 0;
}
