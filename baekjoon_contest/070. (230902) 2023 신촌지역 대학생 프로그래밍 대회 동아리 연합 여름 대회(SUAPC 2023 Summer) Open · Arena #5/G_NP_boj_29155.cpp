// Solve 2023-09-05

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

    int prob_cnt[6] = { 0 };

    for (int difficulty = 1; difficulty <= 5; difficulty++) {
        cin >> prob_cnt[difficulty];
    }

    priority_queue<int, vector<int>, greater<int> > pq_mintop[6];

    for (int i = 0; i < n; i++) {
        int difficulty, t;
        cin >> difficulty >> t;

        pq_mintop[difficulty].push(t);
    }

    int ans = 240;

    for (int difficulty = 1; difficulty <= 5; difficulty++) {
        int first = 0, last = 0;

        for (int i = 0, ie = prob_cnt[difficulty]; i < ie; i++) {
            if (i == 0) first = pq_mintop[difficulty].top();
            if (i == ie - 1) last = pq_mintop[difficulty].top();

            ans += pq_mintop[difficulty].top();
            pq_mintop[difficulty].pop();
        }

        ans += last - first;
    }

    cout << ans << '\n';

    return 0;
}
