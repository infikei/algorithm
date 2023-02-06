#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, M, check;
priority_queue<int> present_box;

int main() {
    fastio;

    cin >> N >> M;

    int c;
    for (int i = 0; i < N; i++) {
        cin >> c;
        present_box.push(c);
    }

    check = 1;
    int w;
    for (int i = 0; i < M; i++) {
        cin >> w;

        if (check > 0) {
            if (w > present_box.top()) {
                check = 0;
            }
            else {
                w = present_box.top() - w;
                present_box.pop();
                present_box.push(w);
            }
        }
    }

    cout << check << '\n';

    return 0;
}