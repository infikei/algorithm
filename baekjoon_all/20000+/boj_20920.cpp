// Solve 2023-04-06
// Update 2023-08-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using psi = pair<string, int>;

struct cmp{
    bool operator()(const psi &a, const psi &b) const {
        if (a.second != b.second) return a.second < b.second;
        if (SIZE(a.first) != SIZE(b.first)) return SIZE(a.first) < SIZE(b.first);
        return a.first > b.first;
    }
};

unordered_map<string, int> hs;
priority_queue<psi, vector<psi>, cmp> pq;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        if (SIZE(word) < m) continue;

        hs[word]++;
    }

    for (auto it = hs.begin(); it != hs.end(); it++) {
        pq.push({ it->first, it->second });
    }

    while (!pq.empty()) {
        cout << pq.top().first << '\n';
        pq.pop();
    }

    return 0;
}
