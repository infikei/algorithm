// Solve 2025-10-25

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

int cut_pos[10000];

int get_cut_count(int max_len, vector<int>& parts) {
    int ret = 0;
    int cur = 0;

    for (int i = (int) size(parts) - 1; i >= 0; i--) {
        cur += parts[i];

        if (cur > max_len) {
            ret++;
            cur = parts[i];
        }
    }

    return ret;
}

int main() {
    FASTIO;

    int l, k, c;
    cin >> l >> k >> c;

    for (int i = 0; i < k; i++) {
        cin >> cut_pos[i];
    }

    sort(cut_pos, cut_pos + k);
    vector<int> parts;
    parts.push_back(cut_pos[0]);
    int max_part = cut_pos[0];

    for (int i = 1; i < k; i++) {
        parts.push_back(cut_pos[i] - cut_pos[i - 1]);
        max_part = max(max_part, parts.back());
    }

    parts.push_back(l - cut_pos[k - 1]);
    max_part = max(max_part, parts.back());

    int low = max_part;
    int high = l - 1;
    int mn = l - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cut_cnt = get_cut_count(mid, parts);

        if (cut_cnt <= c) {
            if (mid < mn) {
                mn = mid;
            }

            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    int mn_first_pos = -1;

    for (int i = 0; i < size(parts); i++) {
        int cut_cnt = 1;
        int cur = 0;

        for (int j = i + 1; j < size(parts); j++) {
            cur += parts[j];

            if (cur > mn) {
                cut_cnt++;
                cur = parts[j];
            }
        }

        if (cut_cnt <= c) {
            mn_first_pos = cut_pos[i];
            break;
        }
    }

    cout << mn << ' ' << mn_first_pos << '\n';
    return 0;
}
