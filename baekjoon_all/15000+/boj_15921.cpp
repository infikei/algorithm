// Solve 2023-02-20
// Update 2023-11-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int score_sum = 0;

    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;

        score_sum += score;
    }

    if (score_sum == 0) {
        cout << "divide by zero\n";
    }
    else {
        cout << "1.00\n";
    }

    return 0;
}
