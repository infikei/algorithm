#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int arr[6];
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }

    int B_distance = max(abs(arr[0] - arr[4]), abs(arr[1] - arr[5]));
    int D_distance = abs(arr[2] - arr[4]) + abs(arr[3] - arr[5]);

    if (B_distance < D_distance) {
        cout << "bessie\n";
    }
    else if (B_distance > D_distance) {
        cout << "daisy\n";
    }
    else {
        cout << "tie\n";
    }

    return 0;
}