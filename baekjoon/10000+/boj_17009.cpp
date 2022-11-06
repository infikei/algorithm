#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int arr[2] = {0, 0};
    for (int i = 0; i < 2; i++) {
        for (int j = 3; j > 0; j--) {
            int x;
            cin >> x;

            arr[i] += x * j;
        }
    }

    if (arr[0] > arr[1]) {
        cout << "A\n";
    }
    else if (arr[0] < arr[1]) {
        cout << "B\n";
    }
    else {
        cout << "T\n";
    }

    return 0;
}