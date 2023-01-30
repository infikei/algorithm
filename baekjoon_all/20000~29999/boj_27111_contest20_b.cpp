#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int MAX_N = 200000;
int n, visited[MAX_N + 1], cnt;

int main() {
    fastio;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (visited[a] == b) cnt++;
        else visited[a] = b;
    }

    for (int i = 1; i <= MAX_N; i++) {
        if (visited[i] == 1) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}