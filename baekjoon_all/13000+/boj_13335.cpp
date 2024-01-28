// Solve 2024-01-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, w, l;
    cin >> n >> w >> l;

    queue<int> trucks_in;

    for (int i = 0; i < n; i++) {
        int truck;
        cin >> truck;

        trucks_in.push(truck);
    }

    queue<pair<int, int>> trucks_out;
    int cur_time = 0;
    int cur_weight_sum = 0;

    while (true) {
        cur_time++;

        if (!trucks_out.empty() && trucks_out.front().second == cur_time) {
            cur_weight_sum -= trucks_out.front().first;
            trucks_out.pop();
        }

        if (!trucks_in.empty() && cur_weight_sum + trucks_in.front() <= l) {
            int truck = trucks_in.front();
            trucks_in.pop();
            cur_weight_sum += truck;
            trucks_out.emplace(truck, cur_time + w);
        }

        if (trucks_in.empty() && trucks_out.empty()) break;
    }

    cout << cur_time << '\n';

    return 0;
}
