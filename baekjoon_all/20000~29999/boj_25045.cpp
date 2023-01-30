#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ull = unsigned long long;

int N, M;
ull ans;
priority_queue<ull> A;
priority_queue<ull, vector<ull>, greater<ull> > B;

int main() {
    fastio;

    cin >> N >> M;

    ull tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A.push(tmp);
    }
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        B.push(tmp);
    }

    while (!A.empty() && !B.empty()) {
        if (A.top() < B.top()) {
            break;
        }
        ans += (A.top() - B.top());
        A.pop(); B.pop();
    }

    cout << ans << '\n';

    return 0;
}