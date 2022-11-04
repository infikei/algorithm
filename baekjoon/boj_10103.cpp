#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int CY = 100, SD = 100;
    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int x, y;
        cin >> x >> y;

        if (x > y) {
            SD -= x;
        }
        else if (x < y) {
            CY -= y;
        }
    }

    cout << CY << '\n';
    cout << SD << '\n';

    return 0;
}