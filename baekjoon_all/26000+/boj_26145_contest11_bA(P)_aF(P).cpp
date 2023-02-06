#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, M, S[2000];

int main() {
    fastio;

    cin >> N >> M;
    int NM = N + M;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++) {
        int x;
        for (int j = 0; j < NM; j++) {
            cin >> x;
            S[i] -= x;
            S[j] += x;
        }
    }

    for (int i = 0; i < NM; i++) {
        cout << S[i] << ' ';
    }
    cout << '\n';

    return 0;
}