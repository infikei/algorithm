// Solve 2025-03-10

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

int arr[500001];

int main() {
    FASTIO;

    int n, h;
    cin >> n >> h;

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;

        if (i & 1) {
            arr[h - len]++;
            arr[h]--;
        }
        else {
            arr[0]++;
            arr[len]--;
        }
    }

    // imos algorithm
    for (int i = 1; i <= h; i++) {
        arr[i] += arr[i - 1];
    }

    int min_num_to_break = 300000;
    int cnt_of_min_num_to_break = 1;

    for (int i = 0; i < h; i++) {
        if (arr[i] < min_num_to_break) {
            min_num_to_break = arr[i];
            cnt_of_min_num_to_break = 1;
        }
        else if (arr[i] == min_num_to_break) {
            cnt_of_min_num_to_break++;
        }
    }

    cout << min_num_to_break << ' ' << cnt_of_min_num_to_break << '\n';

    return 0;
}
