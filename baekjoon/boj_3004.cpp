#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    int ans;
    if (N % 2 == 0) {
        ans = (N / 2 + 1) * (N / 2 + 1);
    }
    else {
        ans = (N / 2 + 1) * (N / 2 + 2);
    }

    cout << ans << '\n';

    return 0;
}