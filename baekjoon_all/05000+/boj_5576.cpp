#include <iostream>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

priority_queue<int> score[2];
int sum_of_top_3[2];

int main() {
    fastio;

    for (int univ = 0; univ < 2; univ++) {
        int x;
        for (int i = 0; i < 10; i++) {
            cin >> x;
            score[univ].push(x);
        }
        for (int i = 0; i < 3; i++) {
            sum_of_top_3[univ] += score[univ].top();
            score[univ].pop();
        }
        cout << sum_of_top_3[univ] << ' ';
    }
    cout << '\n';

    return 0;
}