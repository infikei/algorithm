// Solve 2023-01-08
// Update 2023-12-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int exam_ans[11];

    for (int i = 1; i <= 5; i++) {
        exam_ans[i] = exam_ans[i + 5] = i;
    }

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int cnt = 0;

        for (int j = 1; j <= 10; j++) {
            int x;
            cin >> x;

            if (x == exam_ans[j]) {
                cnt++;
            }
        }

        if (cnt == 10) {
            cout << i << '\n';
        }
    }

    return 0;
}
