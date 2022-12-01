#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N, L;
    cin >> N >> L;

    int left, right;
    bool flag = false;
    for (int l = L; l < 101; l++) {
        if (l > N + 1) {
            break;
        }
        if (l % 2 == 0) {
            int l_half = l / 2;
            if (N % l_half != 0) {
                continue;
            }
            int center_sum = N / l_half;
            if (center_sum % 2 == 0) {
                continue;
            }
            int center = center_sum / 2;
            left = center + 1 - l_half;
            right = center + l_half;
        }
        else {
            if (N % l != 0) {
                continue;
            }
            int center = N / l;
            left = center - l / 2;
            right = center + l / 2;
        }
        if (left < 0) {
            continue;
        }
        flag = true;
        break;
    }

    if (flag) {
        for (int i = left; i <= right; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}