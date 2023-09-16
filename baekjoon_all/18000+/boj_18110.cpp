// Solve 2023-09-15

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

    vector<int> votes(n);

    for (int &x : votes) {
        cin >> x;
    }

    sort(votes.begin(), votes.end());

    int votes_exclude_cnt = round(n * 0.15);
    int votes_sum = 0;

    for (int i = votes_exclude_cnt, ie = n - votes_exclude_cnt; i < ie; i++) {
        votes_sum += votes[i];
    }

    int votes_include_cnt = n - votes_exclude_cnt * 2;

    int votes_level = 0;

    if (votes_include_cnt > 0) {
        votes_level = round((double)votes_sum / votes_include_cnt);
    }

    cout << votes_level << '\n';

    return 0;
}
