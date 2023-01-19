#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<int> vec(n + 1), prefix_sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
        prefix_sum[i] = prefix_sum[i - 1] + vec[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << prefix_sum[e] - prefix_sum[s - 1] << '\n';
    }

    return 0;
}