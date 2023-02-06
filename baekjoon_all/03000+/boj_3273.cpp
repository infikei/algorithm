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

    const int N_MAX = 1e5;
    int n, x, arr[N_MAX];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    sort(arr, arr + n);

    int ans = 0, s = 0, e = n - 1;
    while (s < e) {
        int sum = arr[s] + arr[e];
        if (sum < x) {
            s++;
        }
        else if (sum > x) {
            e--;
        }
        else {
            ans++;
            s++;
            e--;
        }
    }

    cout << ans << '\n';

    return 0;
}