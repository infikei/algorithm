#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int MAX = 101;
int N, A[MAX][MAX], D[MAX][MAX], E[MAX][MAX];

int main() {
    fastio;

    N = MAX - 1;

    // make a new graph
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) A[i][j] = 0;
            else if (i == N || j == N) A[i][j] = 1;
            else A[i][j] = 3;

            E[i][j] = D[i][j] = A[i][j];
        }
    }

    // wrong floyd-warshall
    for (int k = 1; k < N; k++){
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				D[i][j] = min(D[i][k] + D[k][j], D[i][j]);
			}
		}
	}
    // correct floyd-warshall
	for (int k = 1; k <= N; k++){
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				E[i][j] = min(E[i][k] + E[k][j], E[i][j]);
			}
		}
	}

    // count the diff
	int cnt = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (D[i][j] != E[i][j]) cnt++;
		}
	}
    cout << cnt << '\n' << (cnt >= 9700 ? "PASS\n" : "NOT PASS\n");

    return 0;
}