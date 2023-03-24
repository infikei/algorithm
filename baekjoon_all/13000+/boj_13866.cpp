// Solve 2022-11-01
// Update 2023-03-24

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

    int skills[4];
    for (int i = 0; i < 4; i++) {
        cin >> skills[i];
    }
    sort(skills, skills + 4);

    int ans = abs(skills[0] + skills[3] - skills[1] - skills[2]);
    cout << ans << '\n';

    return 0;
}
