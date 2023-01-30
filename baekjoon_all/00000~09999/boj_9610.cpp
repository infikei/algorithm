#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, cnt[5];

int main() {
    fastio;

    cin >> N;

    for (int n = 0; n < N; n++) {
        int x, y;
        cin >> x >> y;

        if (x == 0 || y == 0) {
            cnt[0]++;
        }
        else if (x > 0) {
            if (y > 0) {
                cnt[1]++;
            }
            else {
                cnt[4]++;
            }
        }
        else {
            if (y > 0) {
                cnt[2]++;
            }
            else {
                cnt[3]++;
            }
        }
    }

    for (int i = 1; i < 5; i++) {
        cout << 'Q' << i << ": " << cnt[i] << '\n';
    }
    cout << "AXIS: " << cnt[0] << '\n';

    return 0;
}