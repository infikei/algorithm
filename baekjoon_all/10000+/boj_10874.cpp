// Solve 2023-01-08
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

    int exam_ans[10];
    for (int i = 0; i < 5; i++) {
        exam_ans[i] = exam_ans[i + 5] = i + 1;
    }

    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            int x;
            cin >> x;
            if (x == exam_ans[i]) {
                cnt++;
            }
        }

        if (cnt == 10) {
            cout << k << '\n';
        }
    }

    return 0;
}