// Solve 2023-10-04

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        int scores[6];

        for (int i = 0; i < 6; i++) {
            cin >> scores[i];
        }

        sort(scores, scores + 6);

        if (scores[0] == 0 && scores[5] == 0) break;

        int scores_sum = 0;

        for (int i = 1; i < 5; i++) {
            scores_sum += scores[i];
        }

        int q = scores_sum / 4;
        int r = scores_sum % 4;

        if (r == 0) cout << q << '\n';
        else if (r == 1) cout << q << ".25\n";
        else if (r == 2) cout << q << ".5\n";
        else cout << q << ".75\n";
    }

    return 0;
}
