// Solve 2022-06-03
// Update 2023-02-08

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
#define SETPRECISION(n) cout << fixed << setprecision(n); // boj_1008.cpp (먼저 iomanip을 include해야 한다)
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int t, score[1000];
    cin >> t;

    SETPRECISION(3);

    for (int ti = 0; ti < t; ti++) {
        int n, sum = 0, cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> score[i];
            sum += score[i];
        }

        double avr = (sum * 1.0) / n;
        for (int i = 0; i < n; i++) {
            if (score[i] > avr) {
                cnt++;
            }
        }
        cout << ((cnt * 100.0) / n) << "%\n";
    }

    return 0;
}