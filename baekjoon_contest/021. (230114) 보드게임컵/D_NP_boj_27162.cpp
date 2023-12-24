#include <iostream>
#include <string>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int cnt[7], max_score;
vector<int> v[4];
string s;

int main() {
    fastio;

    cin >> s;
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= 6; i++) {
        v[cnt[i]].push_back(i);
    }

    for (int i = 1; i <= 6; i++) {
        if (s[i - 1] == 'Y') {
            max_score = max(max_score, (cnt[i] + 2) * i);
        }
    }
    if (s[6] == 'Y' && !v[2].empty()) {
        max_score = max(max_score, v[2][0] * 4);
    }
    if (s[7] == 'Y' && !v[3].empty()) {
        max_score = max(max_score, v[3][0] * 3 + v[0][4] * 2);
    }
    if (s[7] == 'Y' && !v[2].empty()) {
        max_score = max(max_score, v[2][0] * 3 + v[1][0] * 2);
        max_score = max(max_score, v[2][0] * 2 + v[1][0] * 3);
    }
    if (s[8] == 'Y' && cnt[6] == 0 && (int)v[1].size() == 3 && (int)v[0].size() == 3) {
        max_score = max(max_score, 30);
    }
    if (s[9] == 'Y' && cnt[1] == 0 && (int)v[1].size() == 3 && (int)v[0].size() == 3) {
        max_score = max(max_score, 30);
    }
    if (s[10] == 'Y' && !v[3].empty()) {
        max_score = max(max_score, 50);
    }
    if (s[11] == 'Y') {
        int tmp = 0;
        for (int i = 1; i <= 6; i++) tmp += cnt[i] * i;
        max_score = max(max_score, tmp + 12);
    }

    cout << max_score << '\n';

    return 0;
}