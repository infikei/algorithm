#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, M, Q;
int mat[3000][3000];
unordered_map<int, int> hs;

int main() {
    fastio;

    cin >> N >> M >> Q;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> mat[row][col];
        }
        hs[row] = row;
    }

    for (int q = 0; q < Q; q++) {
        int query;
        cin >> query;

        if (query == 0) {
            int i, j, k;
            cin >> i >> j >> k;
            mat[hs[i]][j] = k;
        }
        else {
            int i, j;
            cin >> i >> j;
            int t = hs[i];
            hs[i] = hs[j];
            hs[j] = t;
        }
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cout << mat[hs[row]][col] << ' ';
        }
        cout << '\n';
    }

    return 0;
}