// Solve 2023-03-26

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    int arr[100000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 1, insc_cnt = 1, desc_cnt = 1;;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] <= arr[i]) {
            insc_cnt++;
            if (insc_cnt > ans) {
                ans = insc_cnt;
            }
        }
        else {
            insc_cnt = 1;
        }

        if (arr[i - 1] >= arr[i]) {
            desc_cnt++;
            if (desc_cnt > ans) {
                ans = desc_cnt;
            }
        }
        else {
            desc_cnt = 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
