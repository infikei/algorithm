#include <iostream>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N;
priority_queue<int> pq_max;

int main() {
    fastio;

    cin >> N;
    for (int n = 0; n < N; n++) {
        int x;
        cin >> x;
        pq_max.push(x);
    }

    for (int n = 0; n < N; n++) {
        cout << pq_max.top() << '\n';
        pq_max.pop();
    }

    return 0;
}