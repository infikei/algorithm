// Solve 2023-02-07

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    const int MAX_N = 1e5;
    int n, arr[MAX_N];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int left = 0, right = n - 1, ans_left = 0, ans_right = n - 1, ans = 2e9 + 1;
    while (left < right) {
        int val = arr[left] + arr[right];
        if (abs(val) < abs(ans)) {
            ans = val;
            ans_left = left;
            ans_right = right;
        }
        if (val < 0) {
            left++;
        }
        else if (val > 0) {
            right--;
        }
        else {
            break;
        }
    }

    cout << arr[ans_left] << ' ' << arr[ans_right] << '\n';

    return 0;
}