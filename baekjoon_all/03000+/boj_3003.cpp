// Solve 2022-11-06
// Update 2023-02-07

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

    int arr[6] = {1, 1, 2, 2, 2, 8};
    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        cout << arr[i] - x << ' ';
    }
    cout << '\n';

    return 0;
}