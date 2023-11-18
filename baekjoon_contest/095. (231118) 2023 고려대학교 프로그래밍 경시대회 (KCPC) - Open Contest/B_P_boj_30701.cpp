// Solve 2023-11-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll INF = 2e9;

int main() {
    FASTIO;

    priority_queue<int, vector<int>, greater<int> > monster_pq_mintop;
    priority_queue<int, vector<int>, greater<int> > equipment_pq_mintop;

    int n, d;
    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        int a, x;
        cin >> a >> x;

        if (a == 1) monster_pq_mintop.push(x);
        else equipment_pq_mintop.push(x);
    }

    ll cur_combat_power = d;

    while (true) {
        while (true) {
            if (monster_pq_mintop.empty()) break;
            if (cur_combat_power <= monster_pq_mintop.top()) break;

            cur_combat_power += monster_pq_mintop.top();
            monster_pq_mintop.pop();
        }

        if (cur_combat_power > INF) {
            cur_combat_power = INF;
        }

        if (equipment_pq_mintop.empty()) break;

        cur_combat_power *= equipment_pq_mintop.top();
        equipment_pq_mintop.pop();

        if (cur_combat_power > INF) {
            cur_combat_power = INF;
        }
    }

    int ans = n - SIZE(monster_pq_mintop) - SIZE(equipment_pq_mintop);

    cout << ans << '\n';

    return 0;
}
