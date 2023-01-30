#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, K;
string face[100];

int main() {
    fastio;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> face[i];
    }
    cin >> K;

    if (K == 1) {
        for (int i = 0; i < N; i++) {
            cout << face[i] << '\n';
        }
    }
    else if (K == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j >= 0; j--) {
                cout << face[i][j];
            }
            cout << '\n';
        }
    }
    else {
        for (int i = N - 1; i >= 0; i--) {
            cout << face[i] << '\n';
        }
    }

    return 0;
}