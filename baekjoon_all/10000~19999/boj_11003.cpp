#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using pii = pair<int, int>;

deque<pii> DQ;

int main() {
    fastio;

    int N, L;
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        while (!DQ.empty() && DQ.front().second < i) {
            DQ.pop_front();
        }

        while (!DQ.empty() && DQ.back().first >= x) {
            DQ.pop_back();
        }

        DQ.push_back(make_pair(x, i + L - 1));

        cout << DQ.front().first << ' ';
    }

    return 0;
}