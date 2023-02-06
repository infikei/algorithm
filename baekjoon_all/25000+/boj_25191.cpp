#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N, A, B;
    cin >> N >> A >> B;

    int ans = min(N, A / 2 + B);
    cout << ans << '\n';

    return 0;
}