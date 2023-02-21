// Solve 2023-02-21

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
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 10000;
int n, m;
int arr[MAX_N];

int main() {
    FASTIO;

    cin >> n;
    int max_arr = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max_arr = max(max_arr, arr[i]);
    }
    cin >> m;

    int low = 0, high = max_arr + 1;
    while (low + 1 < high) {
        int mid = (low + high) / 2;

        int val = 0;
        for (int i = 0; i < n; i++) {
            val += min(arr[i], mid);
        }

        if (val <= m) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    cout << low << '\n';

    return 0;
}