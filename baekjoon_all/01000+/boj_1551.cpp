// Solve 2024-02-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;
    cin.ignore();

    vector<int> nums(n);

    for (int &x : nums) {
        string w;
        getline(cin, w, ',');
        x = stoi(w);
    }

    for (int ki = 1; ki <= k; ki++) {
        for (int i = n - 1; i >= ki; i--) {
            nums[i] -= nums[i - 1];
        }
    }

    cout << nums[k];

    for (int i = k + 1; i < n; i++) {
        cout << ',' << nums[i];
    }

    cout << '\n';

    return 0;
}
