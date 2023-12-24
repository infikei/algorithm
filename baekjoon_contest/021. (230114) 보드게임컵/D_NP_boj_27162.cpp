// Solve 2023-01-14
// Update 2023-12-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    cin >> s;

    int cnt[7] = { 0 };

    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> vec[4];

    for (int i = 1; i <= 6; i++) {
        vec[cnt[i]].push_back(i);
    }

    int max_score = 0;

    // Ones, Twos, ..., Sixes
    for (int i = 1; i <= 6; i++) {
        if (s[i - 1] == 'Y') {
            max_score = max(max_score, (cnt[i] + 2) * i);
        }
    }

    // Four of a Kind
    if (s[6] == 'Y' && !vec[2].empty()) {
        max_score = max(max_score, vec[2][0] * 4);
    }

    // Full House
    if (s[7] == 'Y' && !vec[3].empty()) {
        max_score = max(max_score, vec[3][0] * 3 + vec[0][4] * 2);
    }

    // Full House
    if (s[7] == 'Y' && !vec[2].empty()) {
        max_score = max(max_score, vec[2][0] * 3 + vec[1][0] * 2);
        max_score = max(max_score, vec[2][0] * 2 + vec[1][0] * 3);
    }

    // Little Straight
    if (s[8] == 'Y' && cnt[6] == 0 && SIZE(vec[1]) == 3) {
        max_score = max(max_score, 30);
    }

    // Big Straight
    if (s[9] == 'Y' && cnt[1] == 0 && SIZE(vec[1]) == 3) {
        max_score = max(max_score, 30);
    }

    // Yacht
    if (s[10] == 'Y' && !vec[3].empty()) {
        max_score = max(max_score, 50);
    }

    // Choice
    if (s[11] == 'Y') {
        int sum = 0;

        for (int i = 1; i <= 6; i++) {
            sum += cnt[i] * i;
        }

        max_score = max(max_score, sum + 12);
    }

    cout << max_score << '\n';

    return 0;
}
