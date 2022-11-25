#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int score = 0, score_diff_with_100 = 100;
    bool flag = false;

    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        if (flag) {
            continue;
        }
        int next_score = score + x;
        int next_score_diff_with_100 = abs(next_score - 100);

        if (score_diff_with_100 > next_score_diff_with_100) {
            score = next_score;
            score_diff_with_100 = next_score_diff_with_100;
        }
        else if (score_diff_with_100 < next_score_diff_with_100) {
            flag = true;
        }
        else {
            flag = true;
            score = next_score;
        }
    }

    cout << score << '\n';

    return 0;
}