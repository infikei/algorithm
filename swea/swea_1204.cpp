// Solve 2024-01-01
// Update 2024-01-29

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int tc;
        cin >> tc;

        int cnt[101] = { 0 };

        for (int i = 0; i < 1000; i++) {
            int score;
            cin >> score;
            cnt[score]++;
        }

        int max_cnt = -1;
        int max_score = -1;

        for (int score = 0; score <= 100; score++) {
            if (cnt[score] >= max_cnt) {
                max_cnt = cnt[score];
                max_score = score;
            }
        }

        cout << '#' << tc << ' ' << max_score << '\n';
    }

    return 0;
}
