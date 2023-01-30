#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int arr[3];

    while (true) {
        bool flag_terminate = true;
        for (int i = 0; i < 3; i++) {
            cin >> arr[i];
            if (arr[i] != 0) {
                flag_terminate = false;
            }
        }
        if (flag_terminate) {
            break;
        }

        if (arr[0] + arr[2] == 2 * arr[1]) {
            cout << "AP " << 2 * arr[2] - arr[1] << '\n';
        }
        else {
            cout << "GP " << arr[2] * arr[2] / arr[1] << '\n';
        }
    }

    return 0;
}