// Solve 2023-01-15
// Update 2023-12-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string s;
        cin >> s;

        bool check_if_infinite = true;

        for (char &c : s) {
            if (c != '0' && c != '1') {
                check_if_infinite = false;
                break;
            }
        }

        if (check_if_infinite) {
            cout << "Hello, BOJ 2023!\n";
            continue;
        }

        int n = stoi(s);
        vector<vector<int>> rhs_sums(SIZE(s), vector<int>());

        for (int i = 0, ie = SIZE(s); i < ie; i++) {
            rhs_sums[i].push_back(stoi(s.substr(0, i + 1)));

            for (int j = 0; j < i; j++) {
                int right = stoi(s.substr(j + 1, i - j));

                for (int left : rhs_sums[j]) {
                    rhs_sums[i].push_back(left + right);
                }
            }

            // 정렬 후 중복 제거
            sort(rhs_sums[i].begin(), rhs_sums[i].end());
            rhs_sums[i].erase(unique(rhs_sums[i].begin(), rhs_sums[i].end()), rhs_sums[i].end());
        }

        int max_rhs_sum = rhs_sums.back().back();
        int iter = 1;
        int ans = 0;

        while (true) {
            ll lhs_sum = 0;

            for (char &c : s) {
                lhs_sum += pow(c - '0', iter);
            }

            if (lhs_sum > max_rhs_sum) break;

            for (int rhs_sum : rhs_sums.back()) {
                if (lhs_sum == rhs_sum) {
                    ans++;
                    break;
                }
            }

            iter++;
        }

        cout << ans << '\n';
    }

    return 0;
}
