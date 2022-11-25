#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    int score, min_val = 1000, max_val = 0;
    for (int n = 0; n < N; n++) {
        cin >> score;
        min_val = min(min_val, score);
        max_val = max(max_val, score);
    }

    cout << max_val - min_val << '\n';

    return 0;
}