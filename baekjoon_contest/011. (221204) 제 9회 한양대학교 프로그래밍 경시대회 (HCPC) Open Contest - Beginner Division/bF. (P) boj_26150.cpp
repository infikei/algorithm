#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N;
priority_queue<pair<int, char> > pq_max;

int main() {
    fastio;

    cin >> N;

    for (int n = 0; n < N; n++) {
        string S;
        int I, D;
        cin >> S >> I >> D;
        char ch = S[D - 1];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - 'a' + 'A';
        }
        pq_max.push(make_pair(-I, ch));
    }

    while (!pq_max.empty()) {
        cout << pq_max.top().second;
        pq_max.pop();
    }
    cout << '\n';

    return 0;
}