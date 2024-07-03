// Solve 2023-12-25

#include <iostream>
#include <string>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int cost_cnt[1002] = { 0 };
    int jinju_cost = 0;

    while (--n >= 0) {
        string name;
        ll cost;
        cin >> name >> cost;

        if (name == "jinju") {
            jinju_cost = cost;
        }

        if (cost > 1000) {
            cost = 1001;
        }

        cost_cnt[cost]++;
    }

    int cnt = 0;

    for (int i = jinju_cost + 1; i <= 1001; i++) {
        cnt += cost_cnt[i];
    }

    cout << jinju_cost << '\n';
    cout << cnt << '\n';

    return 0;
}
