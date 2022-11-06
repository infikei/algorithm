#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cout << '*';
        for (int j = 0; j < (N - 1) / 2; j++) {
            cout << " *";
        }
        cout << '\n';
        for (int j = 0; j < N / 2; j++) {
            cout << " *";
        }
        cout << '\n';
    }

    return 0;
}