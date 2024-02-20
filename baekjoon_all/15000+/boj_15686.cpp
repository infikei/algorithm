// Solve 2022-09-12
// Update 2024-02-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

int n, m;
int min_sum_dist;
vector<pii> houses;
vector<pii> chickens;
vector<int> chicken_selected;

void dfs(int depth = 0, int begin_idx = 0) {
    if (depth == m) {
        int cur_sum_dist = 0;

        for (pii house : houses) {
            int chicken_dist = 100;

            for (int chicken_idx : chicken_selected) {
                chicken_dist = min(chicken_dist, abs(house.first - chickens[chicken_idx].first) + abs(house.second - chickens[chicken_idx].second));
            }

            cur_sum_dist += chicken_dist;
        }

        min_sum_dist = min(min_sum_dist, cur_sum_dist);
        return;
    }

    for (int i = begin_idx; i < SIZE(chickens); i++) {
        chicken_selected.push_back(i);
        dfs(depth + 1, i + 1);
        chicken_selected.pop_back();
    }
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int val;
            cin >> val;

            if (val == 1) {
                houses.emplace_back(x, y);
            }
            else if (val == 2) {
                chickens.emplace_back(x, y);
            }
        }
    }

    min_sum_dist = 10000;
    dfs();
    cout << min_sum_dist << '\n';

    return 0;
}
