#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;

    int v, max_v = 0, sum_v = 0;

    for (int i = 0; i < N; i++) {
        cin >> v;
        max_v = max(max_v, v);
        sum_v += v;
    }

    cout << sum_v - max_v << '\n';

    return 0;
}