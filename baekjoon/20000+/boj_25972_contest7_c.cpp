#include <iostream>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using pii = pair<int, int>;

int N, cnt;
priority_queue<pii, vector<pii>, greater<pii> > domino;

int main() {
    fastio;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, l;
        cin >> a >> l;
        domino.push(make_pair(a, l));
    }

    int prev = 0;
    for (int i = 0; i < N; i++) {
        pii now = domino.top();
        domino.pop();
        if (now.first > prev) {
            cnt++;
        }
        prev = now.first + now.second;
    }

    cout << cnt << '\n';

    return 0;
}