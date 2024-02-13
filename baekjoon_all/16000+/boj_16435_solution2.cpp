// Solve 2023-03-02
// Update 2024-02-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, l;
    cin >> n >> l;

    priority_queue<int, vector<int>, greater<int>> pq_mintop;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq_mintop.push(x);
    }

    for (int i = 0; i < n; i++) {
        if (pq_mintop.top() > l) break;

        pq_mintop.pop();
        l++;
    }

    cout << l << '\n';

    return 0;
}
