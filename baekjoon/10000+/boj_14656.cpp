#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N, cnt = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        if (x != i) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}