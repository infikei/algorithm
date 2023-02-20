// Solve 2023-02-19

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

string graph[9][9];
pair<string, vector<string> > new_graph[8];

int main() {
    FASTIO;

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cin >> graph[row][col];
        }
    }

    int idx = 0;
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            if (row == 3 && col == 3) continue;

            new_graph[idx].first = graph[row + 1][col + 1];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == 1 && j == 1) continue;
                    new_graph[idx].second.push_back(graph[row + i][col + j]);
                }
            }
            sort(ALL(new_graph[idx].second));

            idx++;
        }
    }
    sort(new_graph, new_graph + 8);

    for (int i = 0; i < 8; i++) {
        int ii = i + 1;
        cout << '#' << ii << ". " << new_graph[i].first << '\n';
        for (int j = 0; j < 8; j++) {
            cout << '#' << ii << '-' << j + 1 << ". " << new_graph[i].second[j] << '\n';
        }
    }

    return 0;
}