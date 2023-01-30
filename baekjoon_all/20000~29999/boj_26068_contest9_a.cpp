#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, cnt;

int main() {
    fastio;

    cin >> N;

    string D_DAY;
    int x;
    for (int n = 0; n < N; n++) {
        cin >> D_DAY;
        x = stoi(D_DAY.substr(2, (int)(D_DAY.length()) - 2));
        if (x < 91) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}