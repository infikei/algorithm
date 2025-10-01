// Solve 2025-09-30

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
vector<vector<int>> quests;
bool selected[21];
int ans = 0;

int count_quest() {
    int ret = 0;

    for (vector<int>& quest : quests) {
        bool can_complete = true;

        for (int& skill : quest) {
            if (!selected[skill]) {
                can_complete = false;
                break;
            }
        }

        if (can_complete) {
            ret++;
        }
    }

    return ret;
}

void recur(int depth = 0, int begin_skill = 1) {
    if (depth == n) {
        ans = max(ans, count_quest());
        return;
    }

    for (int i = begin_skill; i <= n * 2; i++) {
        selected[i] = true;
        recur(depth + 1, i + 1);
        selected[i] = false;
    }
}

int main() {
    FASTIO;

    int m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        quests.push_back(vector<int>());
        vector<int>& quest = quests.back();

        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            quest.push_back(x);
        }
    }

    recur();
    cout << ans << '\n';
    return 0;
}
