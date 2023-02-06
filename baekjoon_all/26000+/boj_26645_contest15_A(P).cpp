#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;

    int ans;

    if (N < 206) ans = 1;
    else if (N < 218) ans = 2;
    else if (N < 229) ans = 3;
    else ans = 4;

    cout << ans << '\n';

    return 0;
}