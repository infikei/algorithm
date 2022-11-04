#include <iostream>
#include <string>
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

    string ABC_sequence;
    cin >> ABC_sequence;

    for (auto a : ABC_sequence) {
        cout << arr[a - 'A'] << ' ';
    }
    cout << '\n';

    return 0;
}