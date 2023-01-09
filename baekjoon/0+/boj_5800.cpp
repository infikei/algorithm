#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int k;
    cin >> k;

    for (int i = 1; i <= k; i++) {
        int n;
        cin >> n;

        vector<int> v;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());
        int ans_maxgap = 0;
        for (int j = 1; j < n; j++) {
            ans_maxgap = max(ans_maxgap, v[j] - v[j - 1]);
        }

        cout << "Class " << i << '\n';
        cout << "Max " << v[n - 1] << ", Min " << v[0];
        cout << ", Largest gap " << ans_maxgap << '\n';
    }

    return 0;
}