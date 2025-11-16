// Solve 2023-09-18
// Update 2025-11-15

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int get_minutes(string hhmm) {
    return stoi(hhmm.substr(0, 2)) * 60 + stoi(hhmm.substr(3, 2));
}

bool is_real_virtual_youtuber(vector<int>& week_days, vector<int>& week_minutes) {
    for (int days : week_days) {
        if (days < 5) return false;
    }

    for (int minutes : week_minutes) {
        if (minutes < 3600) return false;
    }

    return true;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    m /= 7;
    unordered_map<string, vector<int>> week_days_map;
    unordered_map<string, vector<int>> week_minutes_map;

    while (n-- > 0) {
        string name, live_start, live_end;
        int day;
        cin >> name >> day >> live_start >> live_end;
        int week = (day - 1) / 7;
        int minutes = get_minutes(live_end) - get_minutes(live_start);

        if (week_days_map.find(name) == week_days_map.end()) {
            week_days_map[name] = vector<int>(m);
            week_minutes_map[name] = vector<int>(m);
        }

        week_days_map[name][week]++;
        week_minutes_map[name][week] += minutes;
    }

    vector<string> real_virtual_youtubers;

    for (auto& [name, week_days] : week_days_map) {
        auto& week_minutes = week_minutes_map[name];

        if (is_real_virtual_youtuber(week_days, week_minutes)) {
            real_virtual_youtubers.push_back(name);
        }
    }

    sort(real_virtual_youtubers.begin(), real_virtual_youtubers.end());

    if (real_virtual_youtubers.empty()) {
        cout << -1 << '\n';
    }
    else {
        for (string& name : real_virtual_youtubers) {
            cout << name << '\n';
        }
    }

    return 0;
}
