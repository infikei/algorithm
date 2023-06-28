// Solve 2022-06-03
// Update 2023-06-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(3);

    int t, score[1000];
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> score[i];
            sum += score[i];
        }

        double avr = (sum * 1.0) / n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (score[i] > avr) {
                cnt++;
            }
        }

        cout << round(cnt * 100000.0 / n) / 1000 << "%\n";
    }

    return 0;
}
