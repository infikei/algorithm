#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int INF = 987654321; // 또는 1e9로 설정
int vertex, edge;
vector<vector<int> > costs;

void floyd_warshall() {
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            for (int k = 0; k < vertex; k++) {
                if (costs[j][i] != INF && costs[i][k] != INF) {
                    costs[j][k] = min(costs[j][k], costs[j][i] + costs[i][k]);
                }
            }
        }
    }
}

int main() {
    fastio;

    cin >> vertex >> edge;
    costs.assign(vertex, vector<int>(vertex, INF));
    for (int i = 0; i < vertex; i++) costs[i][i] = 0;
    for (int i = 0; i < edge; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        costs[from][to] = min(costs[from][to], cost);
        costs[to][from] = min(costs[to][from], cost); // 양방향일 경우
    }

    floyd_warshall();

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << (costs[i][j] == INF ? 0 : costs[i][j]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}