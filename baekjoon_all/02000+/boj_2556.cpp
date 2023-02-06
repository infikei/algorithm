#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    string S;
    for (int i = 0; i < N; i++) {
        S += '*';
    }
    for (int i = 0; i < N; i++) {
        cout << S << '\n';
    }

    return 0;
}