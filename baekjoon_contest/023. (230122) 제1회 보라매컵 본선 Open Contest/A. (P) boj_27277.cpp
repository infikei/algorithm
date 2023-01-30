#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int n, ans;
vector<int> vec;

int main() {
    fastio;

    cin >> n;

    vec.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    ans = vec[n - 1];
    int a = 0, b = n - 2;
    while (a < b) {
        ans += vec[b] - vec[a];
        a++; b--;
    }
    cout << ans << '\n';

    return 0;
}