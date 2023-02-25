// Solve 2023-02-07
// Update 2023-02-22

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

const int MAX_N = 1e5;
int n, arr[MAX_N];

int main() {
    FASTIO;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int low = 0, high = n - 1;
    int ans = 2e9, ans_low = 0, ans_high = 0;
    while (low < high) {
        int val = arr[low] + arr[high];
        if (ans > abs(val)) {
            ans = abs(val);
            ans_low = low;
            ans_high = high;
        }

        if (val < 0) {
            low++;
        }
        else if (val > 0) {
            high--;
        }
        else {
            break;
        }
    }

    cout << arr[ans_low] << ' ' << arr[ans_high] << '\n';

    return 0;
}