#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    int ans = (1 << N) + 1;
    ans = ans * ans;
    cout << ans << '\n';

    return 0;
}