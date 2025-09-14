// Solve 2025-09-13

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

int n;
int member_order[11];
int group_limit[4];
int score[11][4];
int group_order[4];
int max_score_sum = -INF;
int min_swap_cnt = INF;

int count_swap(vector<int>& member_group) {
    vector<pii> vec;
    vec.emplace_back(0, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            if (member_group[member_order[i]] == group_order[j]) {
                vec.emplace_back(j, i);
                break;
            }
        }
    }

    sort(vec.begin(), vec.end());
    int ret = 0;

    for (int i = 1; i <= n; i++) {
        while (vec[i].second != i) {
            int j = vec[i].second;
            swap(vec[i], vec[j]);
            ret++;
        }
    }

    return ret;
}

void recur(int member_num, int score_sum, vector<int>& member_group, vector<int>& group_member_cnt) {
    if (member_num == n + 1) {
        if (score_sum > max_score_sum) {
            max_score_sum = score_sum;
            min_swap_cnt = count_swap(member_group);
        }
        else if (score_sum == max_score_sum) {
            min_swap_cnt = min(min_swap_cnt, count_swap(member_group));
        }

        return;
    }

    for (int i = 0; i <= 3; i++) {
        member_group[member_num] = i;
        score_sum += score[member_num][i];
        group_member_cnt[i]++;

        if (group_member_cnt[i] <= group_limit[i]) {
            recur(member_num + 1, score_sum, member_group, group_member_cnt);
        }

        group_member_cnt[i]--;
        score_sum -= score[member_num][i];
    }
}

void input() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> member_order[i];
    }

    group_limit[0] = INF;

    for (int i = 1; i <= 3; i++) {
        cin >> group_limit[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            cin >> score[i][j];
        }
    }

    for (int i = 0; i <= 3; i++) {
        cin >> group_order[i];
    }
}

void pro() {
    vector<int> member_group(n + 1);
    vector<int> group_member_cnt(4);
    recur(1, 0, member_group, group_member_cnt);
    cout << min_swap_cnt << '\n';
}

int main() {
    FASTIO;

    input();
    pro();
    return 0;
}
