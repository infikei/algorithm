// Solve 2025-07-27

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
using pis = pair<int, string>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<pis> algo;
unordered_map<string, int> member_idx;
vector<vector<pis>> sorted_algo;

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string algo_name;
        int algo_difficulty;
        cin >> algo_name >> algo_difficulty;
        algo.emplace_back(algo_difficulty, algo_name);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string member_name;
        int member_tier;
        cin >> member_name >> member_tier;
        member_idx[member_name] = i;
        vector<pis> vec;

        for (int j = 0; j < n; j++) {
            vec.emplace_back(abs(member_tier - algo[j].first), algo[j].second);
        }

        sort(vec.begin(), vec.end());
        sorted_algo.push_back(vec);
    }

    int q;
    cin >> q;
    string cur_member_name;
    int cur_member_idx = 0;

    while (q-- > 0) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        if (s2 == "-") {
            cur_member_name = s1;
            cur_member_idx = member_idx[cur_member_name];
            cout << "hai!" << '\n';
        }
        else {
            cout << sorted_algo[cur_member_idx][1].second << " yori mo " << sorted_algo[cur_member_idx][0].second << '\n';
        }
    }

    return 0;
}
