#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N, cnt = 0, milk = 0;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int store;
        cin >> store;

        if (store == milk) {
            cnt++;
            milk = (milk + 1) % 3;
        }
    }

    cout << cnt << '\n';

    return 0;
}