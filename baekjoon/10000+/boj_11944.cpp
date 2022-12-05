#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    string N;
    int M;
    cin >> N >> M;

    int N_len = N.length();
    int output_len = min(stoi(N) * N_len, M);

    while (output_len >= N_len) {
        cout << N;
        output_len -= N_len;
    }
    if (output_len > 0) {
        cout << N.substr(0, output_len) << '\n';
    }

    return 0;
}