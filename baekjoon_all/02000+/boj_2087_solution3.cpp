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
unordered_map<int, int> mp;

void recur1(int depth, int cur_sum, int selected, int arr_size) {
    if (depth == arr_size) {
        mp.emplace(cur_sum, selected);
        return;
    }

    recur1(depth + 1, cur_sum, selected, arr_size);
    recur1(depth + 1, cur_sum + nums[0][depth], selected | (1 << depth), arr_size);
}

bool recur2(int depth, int cur_sum, int selected, int arr_size) {
    if (depth == arr_size) {
        auto it = mp.find(k - cur_sum);

        if (it != mp.end()) {
            for (int i = 0; i < n2; i++) {
                cout << !!(it->second & (1 << i));
            }

            for (int i = 0; i < n - n2; i++) {
                cout << !!(selected & (1 << i));
            }

            cout << '\n';
            return true;
        }

        return false;
    }

    if (recur2(depth + 1, cur_sum, selected, arr_size)) return true;
    if (recur2(depth + 1, cur_sum + nums[1][depth], selected | (1 << depth), arr_size)) return true;
    return false;
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
    recur1(0, 0, 0, n2);
    recur2(0, 0, 0, n - n2);
}

int main() {
    FASTIO;

    input();
    pro();

    return 0;
}
