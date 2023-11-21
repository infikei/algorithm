// Solve 2023-11-21

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

    string max_name;
    int max_score = 0;

    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;

        if (score > max_score) {
            max_score = score;
            max_name = name;
        }
        else if (score == max_score && name < max_name) {
            max_name = name;
        }
    }

    cout << max_name << '\n';

    return 0;
}
