// Solve 2023-02-15

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

    int a[2], b[2];
    for (int i = 0; i < 2; i++) {
        cin >> a[i] >> b[i];
    }

    int p[3];
    for (int i = 0; i < 3; i++) {
        cin >> p[i];
    }

    int ans[3] = { 0 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if ((p[i] - 1) % (a[j] + b[j]) < a[j]) {
                ans[i]++;
            }
        }
    }

    for (auto a : ans) {
        cout << a << '\n';
    }

    return 0;
}