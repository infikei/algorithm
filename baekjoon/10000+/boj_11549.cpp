#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    int cnt = 0;

    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;

        if (x == T) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}