// Solve 2023-11-26

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

    int a[100];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    int b[100];

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> ans_vec;
    int i0 = 0;
    int j0 = 0;

    for (int num = 100; num >= 1; num--) {
        vector<int> idx_of_num_in_a;

        for (int i = i0; i < n; i++) {
            if (a[i] == num) {
                idx_of_num_in_a.push_back(i);
            }
        }

        vector<int> idx_of_num_in_b;

        for (int j = j0; j < m; j++) {
            if (b[j] == num) {
                idx_of_num_in_b.push_back(j);
            }
        }

        int add_cnt = min(SIZE(idx_of_num_in_a), SIZE(idx_of_num_in_b));

        for (int k = 0; k < add_cnt; k++) {
            ans_vec.push_back(num);
        }

        if (add_cnt > 0) {
            i0 = idx_of_num_in_a[add_cnt - 1] + 1;
            j0 = idx_of_num_in_b[add_cnt - 1] + 1;
        }
    }

    cout << SIZE(ans_vec) << '\n';

    for (int x : ans_vec) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}
