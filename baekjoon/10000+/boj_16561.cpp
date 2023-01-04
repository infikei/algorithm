#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;

    int N3 = N / 3;
    int ans = (N3 - 2) * (N3 - 1) / 2;
    cout << ans << '\n';

    return 0;
}