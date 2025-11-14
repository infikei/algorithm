// Solve 2023-09-18
// Update 2025-11-12

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

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    m /= 7;

    unordered_map<string, int> name_to_idx;
    vector<string> idx_to_name;
    vector<vector<int>> day_cnt;
    vector<vector<int>> hour_cnt;

    for (int i = 0; i < n; i++) {
        string name, t_s_str, t_e_str;
        int day;
        cin >> name >> day >> t_s_str >> t_e_str;

        int week = (day - 1) / 7;
        int t_s = stoi(t_s_str.substr(0, 2)) * 60 + stoi(t_s_str.substr(3, 2));
        int t_e = stoi(t_e_str.substr(0, 2)) * 60 + stoi(t_e_str.substr(3, 2));
        int idx;

        if (name_to_idx.find(name) == name_to_idx.end()) {
            idx = size(name_to_idx);
            name_to_idx[name] = idx;
            day_cnt.push_back(vector<int>(m, 0));
            hour_cnt.push_back(vector<int>(m, 0));
            idx_to_name.push_back(name);
        }
        else {
            idx = name_to_idx[name];
        }

        day_cnt[idx][week]++;
        hour_cnt[idx][week] += t_e - t_s;
    }

    vector<string> ans;

    for (int i = 0; i < size(idx_to_name); i++) {
        bool flag = true;

        for (int j = 0; j < m; j++) {
            if (day_cnt[i][j] < 5 || hour_cnt[i][j] < 3600) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans.push_back(idx_to_name[i]);
        }
    }

    if (ans.empty()) {
        cout << -1 << '\n';
    }
    else {
        sort(ans.begin(), ans.end());

        for (string& a : ans) {
            cout << a << '\n';
        }
    }

    return 0;
}
