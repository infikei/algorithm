#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pss = pair<string, string>;

struct cmp {
    bool operator()(pss a, pss b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int N;
priority_queue<pss, vector<pss>, cmp> pq;

int main() {
    fastio;

    cin >> N;

    string a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        pq.push(make_pair(a, b));
    }

    while (!pq.empty()) {
        pss pq_top = pq.top();
        cout << pq_top.first << ' ' << pq_top.second << '\n';
        pq.pop();
    }

    return 0;
}