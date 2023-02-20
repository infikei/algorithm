// Solve 2023-02-20

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

int gandalf[6] = { 1, 2, 3, 3, 4, 10 };
int sauron[7] = { 1, 2, 2, 2, 3, 5, 10 };

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int gandalf_sum = 0, sauron_sum = 0;

        for (int i = 0; i < 6; i++) {
            int x;
            cin >> x;
            gandalf_sum += x * gandalf[i];
        }

        for (int i = 0; i < 7; i++) {
            int x;
            cin >> x;
            sauron_sum += x * sauron[i];
        }

        if (gandalf_sum > sauron_sum) {
            cout << "Battle " << ti << ": Good triumphs over Evil\n";
        }
        else if (gandalf_sum < sauron_sum) {
            cout << "Battle " << ti << ": Evil eradicates all trace of Good\n";
        }
        else {
            cout << "Battle " << ti << ": No victor on this battle field\n";
        }
    }

    return 0;
}