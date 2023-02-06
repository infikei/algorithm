#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    const int MAX_N = 100;
    int n, m;
    cin >> n >> m;

    int arr[MAX_N + 1];
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    for (int k = 0; k < m; k++) {
        int start, end;
        cin >> start >> end;
        reverse(arr + start, arr + end + 1);
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}