// Solve 2023-04-06

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

struct cmp {
    bool operator()(pair<string, int> a, pair<string, int> b) {
        if (a.second == b.second) {
            if (SIZE(a.first) == SIZE(b.first)) {
                return a.first > b.first;
            }
            return SIZE(a.first) < SIZE(b.first);
        }
        return a.second < b.second;
    }
};

unordered_map<string, int> hs;
priority_queue<pair<string, int>, vector<pair<string, int> >, cmp > pq;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        if (SIZE(word) < m) {
            continue;
        }

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
