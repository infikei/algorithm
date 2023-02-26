// Solve 2023-02-26

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int arr[500000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    int ans1_avr = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ans1_avr += arr[i];
    }
    ans1_avr = round(ans1_avr * 1.0 / n);

    sort(arr, arr + n);
    int ans2_center = arr[n / 2];
    int ans4_range = arr[n - 1] - arr[0];

    vector<int> ans3_most_vals;
    int most_cnt = 0, now_val = -10000, now_cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            if (now_cnt > most_cnt) {
                most_cnt = now_cnt;
                ans3_most_vals.clear();
                ans3_most_vals.push_back(now_val);
            }
            else if (now_cnt == most_cnt) {
                ans3_most_vals.push_back(now_val);
            }
            break;
        }

        if (arr[i] == now_val) {
            now_cnt++;
        }
        else {
            if (now_cnt > most_cnt) {
                most_cnt = now_cnt;
                ans3_most_vals.clear();
                ans3_most_vals.push_back(now_val);
            }
            else if (now_cnt == most_cnt) {
                ans3_most_vals.push_back(now_val);
            }
            now_val = arr[i];
            now_cnt = 1;
        }
    }

    cout << ans1_avr << '\n';
    cout << ans2_center << '\n';
    if (SIZE(ans3_most_vals) >= 2) {
        sort(ALL(ans3_most_vals));
        cout << ans3_most_vals[1] << '\n';
    }
    else {
        cout << ans3_most_vals[0] << '\n';
    }
    cout << ans4_range << '\n';

    return 0;
}