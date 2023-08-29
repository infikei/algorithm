// Solve 2023-08-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Problem{
    int l, g;
    Problem(int l = 0, int g = 0) : l(l), g(g) {}
};

struct Problem2{
    int l, p;
    Problem2(int l = 0, int p = 0) : l(l), p(p) {}
    bool operator<(const Problem2 &rhs) const {
        if (l != rhs.l) return l < rhs.l;
        return p < rhs.p;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    Problem problem_info[100001];
    set<Problem2> algorithm_set[101];
    set<int> level_set[101];

    for (int i = 0; i < n; i++) {
        int p, l, g;
        cin >> p >> l >> g;

        problem_info[p] = { l, g };
        algorithm_set[g].insert(Problem2(l, p));
        level_set[l].insert(p);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "recommend") {
            int g, x;
            cin >> g >> x;

            if (x == 1) {
                cout << algorithm_set[g].rbegin()->p << '\n';
            }
            else {
                cout << algorithm_set[g].begin()->p << '\n';
            }
        }
        else if (cmd == "recommend2") {
            int x;
            cin >> x;

            if (x == 1) {
                for (int l = 100; l >= 1; l--) {
                    if (level_set[l].empty()) continue;

                    cout << *level_set[l].rbegin() << '\n';
                    break;
                }
            }
            else {
                for (int l = 1; l <= 100; l++) {
                    if (level_set[l].empty()) continue;

                    cout << *level_set[l].begin() << '\n';
                    break;
                }
            }
        }
        else if (cmd == "recommend3") {
            int x, l;
            cin >> x >> l;

            if (x == 1) {
                for (int ll = l; ll <= 101; ll++) {
                    if (ll == 101) {
                        cout << -1 << '\n';
                        break;
                    }

                    if (level_set[ll].empty()) continue;

                    cout << *level_set[ll].begin() << '\n';
                    break;
                }
            }
            else {
                for (int ll = l - 1; ll >= 0; ll--) {
                    if (ll == 0) {
                        cout << -1 << '\n';
                        break;
                    }

                    if (level_set[ll].empty()) continue;

                    cout << *level_set[ll].rbegin() << '\n';
                    break;
                }
            }
        }
        else if (cmd == "add") {
            int p, l, g;
            cin >> p >> l >> g;

            problem_info[p] = { l, g };
            algorithm_set[g].insert(Problem2(l, p));
            level_set[l].insert(p);
        }
        else {
            int p;
            cin >> p;

            Problem cur = problem_info[p];
            problem_info[p] = { 0, 0 };
            algorithm_set[cur.g].erase({ cur.l, p });
            level_set[cur.l].erase(p);
        }
    }

    return 0;
}
