// Solve 2023-05-20

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

struct Member{
    int p;
    string y, s;
};

Member team[3];

bool cmp_member_1(const Member &a, const Member &b) {
    return a.y < b.y;
}

bool cmp_member_2(const Member &a, const Member &b) {
    return a.p > b.p;
}

int main() {
    FASTIO;

    for (int i = 0; i < 3; i++) {
        cin >> team[i].p >> team[i].y >> team[i].s;
    }

    sort(team, team + 3, cmp_member_1);
    for (int i = 0; i < 3; i++) {
        cout << team[i].y.substr(2, 2);
    }
    cout << '\n';

    sort(team, team + 3, cmp_member_2);
    for (int i = 0; i < 3; i++) {
        cout << team[i].s[0];
    }
    cout << '\n';

    return 0;
}
