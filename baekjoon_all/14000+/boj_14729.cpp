// Solve 2023-10-28

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

    priority_queue<double> pq_maxtop;

    for (int i = 0; i < 7; i++) {
        double x;
        cin >> x;

        pq_maxtop.push(x);
    }

    for (int i = 7; i < n; i++) {
        double x;
        cin >> x;

        pq_maxtop.push(x);
        pq_maxtop.pop();
    }

    vector<double> ans;

    while (!pq_maxtop.empty()) {
        ans.push_back(pq_maxtop.top());
        pq_maxtop.pop();
    }

    SETPRECISION(3);

    for (auto it = ans.rbegin(); it != ans.rend(); it++) {
        cout << *it << '\n';
    }

    return 0;
}
