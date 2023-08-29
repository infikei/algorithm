// Solve 2022-09-09
// Update 2023-08-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Problem{
    int p, l;
    Problem(int p = 0, int l = 0) : p(p), l(l) {}
    bool operator<(const Problem &rhs) const {
        if (l != rhs.l) return l < rhs.l;
        return p < rhs.p;
    }
    bool operator>(const Problem &rhs) const {
        if (l != rhs.l) return l > rhs.l;
        return p > rhs.p;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    unordered_map<int, int> hs;
    priority_queue<Problem> pq_maxtop;
    priority_queue<Problem, vector<Problem>, greater<Problem> > pq_mintop;

    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;

        hs[p] = l;
        pq_maxtop.emplace(p, l);
        pq_mintop.emplace(p, l);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string cmd;
        cin >> cmd;

        if (cmd[0] == 'r') {
            int x;
            cin >> x;

            if (x == 1) {
                while (hs[pq_maxtop.top().p] != pq_maxtop.top().l) {
                    pq_maxtop.pop();
                }

                cout << pq_maxtop.top().p << '\n';
            }
            else {
                while (hs[pq_mintop.top().p] != pq_mintop.top().l) {
                    pq_mintop.pop();
                }

                cout << pq_mintop.top().p << '\n';
            }
        }
        else if (cmd[0] == 'a') {
            int p, l;
            cin >> p >> l;

            hs[p] = l;
            pq_maxtop.emplace(p, l);
            pq_mintop.emplace(p, l);
        }
        else {
            int p;
            cin >> p;

            hs[p] = -1;
        }
    }

    return 0;
}
