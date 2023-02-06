#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int INF = 987654321;
int n, m, k, railro_ticket_cost, cost_without_railro, cost_with_railro;
unordered_map<string, int> city_hs;
vector<int> tour_city;
vector<vector<int> > cost_without_railro_dp, cost_with_railro_dp;

void input() {
    cin >> n >> railro_ticket_cost;
    for (int i = 0; i < n; i++) {
        string city;
        cin >> city;
        city_hs[city] = i;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        string city;
        cin >> city;
        tour_city.push_back(city_hs[city]);
    }
    cin >> k;
    cost_without_railro_dp.assign(n, vector<int>(n, INF));
    cost_with_railro_dp.assign(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        cost_without_railro_dp[i][i] = 0;
        cost_with_railro_dp[i][i] = 0;
    }
    for (int i = 0; i < k; i++) {
        string vehicle, start, end;
        int cost;
        cin >> vehicle >> start >> end >> cost;
        int start_idx = city_hs[start], end_idx = city_hs[end];

        cost_without_railro_dp[start_idx][end_idx] = min(cost_without_railro_dp[start_idx][end_idx], cost * 2);
        cost_without_railro_dp[end_idx][start_idx] = min(cost_without_railro_dp[end_idx][start_idx], cost * 2);

        if (vehicle == "Mugunghwa" || vehicle == "ITX-Saemaeul" || vehicle == "ITX-Cheongchun") {
            cost_with_railro_dp[start_idx][end_idx] = 0;
            cost_with_railro_dp[end_idx][start_idx] = 0;
        }
        else if (vehicle == "S-Train" || vehicle == "V-Train") {
            cost_with_railro_dp[start_idx][end_idx] = min(cost_with_railro_dp[start_idx][end_idx], cost);
            cost_with_railro_dp[end_idx][start_idx] = min(cost_with_railro_dp[end_idx][start_idx], cost);
        }
        else {
            cost_with_railro_dp[start_idx][end_idx] = min(cost_with_railro_dp[start_idx][end_idx], cost * 2);
            cost_with_railro_dp[end_idx][start_idx] = min(cost_with_railro_dp[end_idx][start_idx], cost * 2);
        }
    }
}

void floyd_warshall() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cost_without_railro_dp[j][k] = min(cost_without_railro_dp[j][k], cost_without_railro_dp[j][i] + cost_without_railro_dp[i][k]);
                cost_with_railro_dp[j][k] = min(cost_with_railro_dp[j][k], cost_with_railro_dp[j][i] + cost_with_railro_dp[i][k]);
            }
        }
    }
}

void calc_cost() {
    for (int i = 1; i < m; i++) {
        int s = tour_city[i - 1], e = tour_city[i];
        cost_without_railro += cost_without_railro_dp[s][e];
        cost_with_railro += cost_with_railro_dp[s][e];
    }
    cost_without_railro /= 2;
    cost_with_railro /= 2;
    cost_with_railro += railro_ticket_cost;
}

int main() {
    fastio;

    input();

    floyd_warshall();

    calc_cost();

    if (cost_with_railro < cost_without_railro) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}