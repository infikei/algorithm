// Solve 2023-09-14
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    unordered_map<int, int> mp;
    int cnt = n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        mp[x]++;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a_cnt;
        cin >> a_cnt;

        vector<int> a(a_cnt);

        for (int &x : a) {
            cin >> x;
        }

        bool check = true;

        for (int j = 0; j < a_cnt; j++) {
            if (--mp[a[j]] < 0) {
                check = false;

                for (int jj = 0; jj <= j; jj++) {
                    mp[a[jj]]++;
                }

                break;
            }
        }

        int b_cnt;
        cin >> b_cnt;

        for (int j = 0; j < b_cnt; j++) {
            int x;
            cin >> x;

            if (check) mp[x]++;
        }

        if (check) cnt += b_cnt - a_cnt;
    }

    cout << cnt << '\n';

    if (cnt > 0) {
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int it_val = it->first;
            int it_cnt = it->second;

            for (int i = 0; i < it_cnt; i++) {
                cout << it_val << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
