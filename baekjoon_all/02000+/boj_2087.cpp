// Solve 2025-06-15

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

int n, n2, k;
int nums[2][20];
map<int, int> mp[2];

void recur(int depth, int cur_sum, int selected, int arr_idx, int arr_size) {
    if (depth == arr_size) {
        mp[arr_idx].emplace(cur_sum, selected);
        return;
    }

    recur(depth + 1, cur_sum, selected, arr_idx, arr_size);
    recur(depth + 1, cur_sum + nums[arr_idx][depth], selected | (1 << depth), arr_idx, arr_size);
}

void input() {
    cin >> n;
    n2 = n / 2;

    for (int i = 0; i < n2; i++) {
        cin >> nums[0][i];
    }

    for (int i = n2; i < n; i++) {
        cin >> nums[1][i - n2];
    }

    cin >> k;
}

void pro() {
    recur(0, 0, 0, 0, n2);
    recur(0, 0, 0, 1, n - n2);

    auto it = mp[0].begin();
    auto it2 = mp[1].rbegin();

    while (true) {
        int cur_sum = it->first + it2->first;

        if (cur_sum == k) {
            for (int i = 0; i < n2; i++) {
                cout << !!(it->second & (1 << i));
            }

            for (int i = 0; i < n - n2; i++) {
                cout << !!(it2->second & (1 << i));
            }

            cout << '\n';
            return;
        }

        if (cur_sum < k) {
            it++;

            if (it == mp[0].end()) break;
        }
        else {
            it2++;

            if (it2 == mp[1].rend()) break;
        }
    }
}

int main() {
    FASTIO;

    input();
    pro();

    return 0;
}
