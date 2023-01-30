#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, M, ans;
vector<int> K;
vector<bool> vec;

int main() {
    fastio;

    cin >> N >> M;
    K.assign(M, 0);
    vec.assign(N + 1, false);
    for (int i = 0; i < M; i++) {
        cin >> K[i];
    }

    for (auto k : K) {
        for (int i = k; i <= N; i += k) vec[i] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (vec[i]) ans += i;
    }

    cout << ans << '\n';

    return 0;
}