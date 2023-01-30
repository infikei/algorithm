#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int arr[3];

int main() {
    fastio;

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 3);

    if (3 * arr[1] == 2 * arr[0] + arr[2]) {
        cout << 2 * arr[1] - arr[0] << '\n';
    }
    else if (3 * arr[1] == arr[0] + 2 * arr[2]) {
        cout << 2 * arr[1] - arr[2] << '\n';
    }
    else {
        cout << 2 * arr[2] - arr[1] << '\n';
    }

    return 0;
}