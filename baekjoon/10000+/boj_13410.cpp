#include <iostream>
#include <string>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int reverse_int(int n) {
    string n_str = to_string(n);
    reverse(n_str.begin(), n_str.end());
    return stoi(n_str);
}

int main() {
    fastio;

    int N, K;
    cin >> N >> K;

    int ans = reverse_int(N);
    for (int i = 2; i <= K; i++) {
        int tmp = reverse_int(N * i);
        if (tmp > ans) ans = tmp;
    }

    cout << ans << '\n';

    return 0;
}