// Solve 2023-09-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, p, win, lose, goal;
    cin >> n >> p >> win >> lose >> goal;

    unordered_map<string, int> mp;

    for (int i = 0; i < p; i++) {
        string player_name;
        char win_or_lose;
        cin >> player_name >> win_or_lose;

        if (win_or_lose == 'W') {
            mp[player_name] = 1;
        }
        else {
            mp[player_name] = -1;
        }
    }

    bool ans = false;
    int now_score = 0;

    for (int i = 0; i < n; i++) {
        string player_name;
        cin >> player_name;

        if (mp.find(player_name) == mp.end() || mp[player_name] == -1) {
            now_score -= lose;
        }
        else {
            now_score += win;
        }

        if (now_score < 0) now_score = 0;
        if (now_score >= goal) ans = true;
    }

    if (ans) cout << "I AM NOT IRONMAN!!\n";
    else cout << "I AM IRONMAN!!\n";

    return 0;
}
