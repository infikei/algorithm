// Solve 2022-11-28
// Update 2023-08-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    for (int univ = 0; univ < 2; univ++) {
        int scores[10];

        for (int i = 0; i < 10; i++) {
            cin >> scores[i];
        }

        sort(scores, scores + 10);

        int sum_of_top_3 = 0;

        for (int i = 7; i < 10; i++) {
            sum_of_top_3 += scores[i];
        }

        cout << sum_of_top_3 << ' ';
    }

    cout << '\n';

    return 0;
}
