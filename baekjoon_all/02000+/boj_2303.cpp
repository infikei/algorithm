// Solve 2023-05-10

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
using pii = pair<int, int>;

int main() {
    FASTIO;

    int n;
    cin >> n;

    priority_queue<pii> pq_max;

    for (int p = 1; p <= n; p++) {
        vector<int> v(5);
        int val = 0;
        for (int i = 0; i < 5; i++) {
            cin >> v[i];
        }

        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                int x = v[i] + v[j];
                for (int k = j + 1; k < 5; k++) {
                    val = max(val, (x + v[k]) % 10);
                }
            }
        }

        pq_max.push({ val, p });
    }

    cout << pq_max.top().second << '\n';

    return 0;
}
