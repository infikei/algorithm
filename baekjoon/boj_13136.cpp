#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ull = unsigned long long;

int main() {
    fastio;

    ull R, C, N;
    cin >> R >> C >> N;

    ull ans = ((R - 1) / N + 1) * ((C - 1) / N + 1);
    cout << ans << '\n';

    return 0;
}