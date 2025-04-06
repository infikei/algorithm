// Solve 2023-02-26
// Update 2025-04-06

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int arr[500000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int avg = round((double) sum / n);

    sort(arr, arr + n);
    int median = arr[n / 2];
    int range = arr[n - 1] - arr[0];

    vector<int> mode;

    int mode_cnt = 0;
    int cur = -10000;
    int cur_cnt = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == cur) {
            cur_cnt++;
        }
        else {
            if (cur_cnt > mode_cnt) {
                mode_cnt = cur_cnt;
                mode.clear();
                mode.push_back(cur);
            }
            else if (cur_cnt == mode_cnt) {
                mode.push_back(cur);
            }

            cur = arr[i];
            cur_cnt = 1;
        }
    }

    if (cur_cnt > mode_cnt) {
        mode_cnt = cur_cnt;
        mode.clear();
        mode.push_back(cur);
    }
    else if (cur_cnt == mode_cnt) {
        mode.push_back(cur);
    }

    cout << avg << '\n';
    cout << median << '\n';

    if (mode.size() >= 2) {
        sort(mode.begin(), mode.end());
        cout << mode[1] << '\n';
    }
    else {
        cout << mode[0] << '\n';
    }

    cout << range << '\n';

    return 0;
}
