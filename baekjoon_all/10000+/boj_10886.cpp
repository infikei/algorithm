// Solve 2022-10-23
// Update 2023-03-04

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

    int cnt[2] = { 0 };
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    if (cnt[0] > cnt[1]) {
        cout << "Junhee is not cute!\n";
    }
    else {
        cout << "Junhee is cute!\n";
    }

    return 0;
}