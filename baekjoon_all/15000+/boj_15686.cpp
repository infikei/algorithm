// Solve 2022-09-12
// Update 2024-01-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

int n, m;
int min_dist_sum;
vector<pii> house_list;
vector<pii> chicken_list;
vector<pii> chicken_selected;

void dfs(int depth = 0, int idx = 0) {
    if (depth == m) {
        int cur_dist_sum = 0;

        for (pii house : house_list) {
            int chicken_dist = 100;

            for (pii chicken : chicken_selected) {
                chicken_dist = min(chicken_dist, abs(house.first - chicken.first) + abs(house.second - chicken.second));
            }

            cur_dist_sum += chicken_dist;
        }

        min_dist_sum = min(min_dist_sum, cur_dist_sum);
        return;
    }

    for (int i = idx; i < SIZE(chicken_list); i++) {
        chicken_selected.push_back(chicken_list[i]);
        dfs(depth + 1, i + 1);
        chicken_selected.pop_back();
    }
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;

            if (x == 1) {
                house_list.emplace_back(i, j);
            }
            else if (x == 2) {
                chicken_list.emplace_back(i, j);
            }
        }
    }

    min_dist_sum = 10000;
    dfs();
    cout << min_dist_sum << '\n';

    return 0;
}
