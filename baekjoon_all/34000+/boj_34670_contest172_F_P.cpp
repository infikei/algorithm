// Solve 2025-11-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

bool query(vector<string>& nums) {
    if (size(nums) == 1) return false;

    vector<int> tails;

    for (string& num : nums) {
        if (num[size(num) - 3] == '-') {
            return false;
        }

        int tail = stoi(num.substr(size(num) - 2, 2));
        tails.push_back(tail);
    }

    for (int i = 1; i < size(tails); i++) {
        if (tails[i] != tails[0]) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    int q;
    cin >> q;

    while (q-- > 0) {
        int n;
        cin >> n;

        vector<string> nums(n);

        for (string& num : nums) {
            cin >> num;
        }

        cout << (query(nums) ? "YES" : "NO") << '\n';
    }

    return 0;
}
