#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using vint = vector<int>;

int N, K;
vint route, parent;

int main() {
    fastio;

    cin >> N;
    route.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> route[i];
        K = max(K, route[i]);
    }

    K++;
    parent.assign(K, -2);
    parent[route[0]] = -1;
    for (int i = 1; i < N; i++) {
        if (parent[route[i]] == -2) {
            parent[route[i]] = route[i - 1];
        }
    }

    cout << K << '\n';
    for (auto a : parent) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}