// Solve 2024-02-21
// Update 2025-03-04

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;
    cin.ignore();

    vector<int> nums(n);

    for (int &num : nums) {
        string w;
        getline(cin, w, ',');
        num = stoi(w);
    }

    for (int i = 1; i <= k; i++) {
        for (int j = n - 1; j >= i; j--) {
            nums[j] -= nums[j - 1];
        }
    }

    for (int i = k; i < n - 1; i++) {
        cout << nums[i] << ',';
    }

    cout << nums[n - 1] << '\n';

    return 0;
}
