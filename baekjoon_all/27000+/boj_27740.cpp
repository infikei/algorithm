// Solve 2025-12-17

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

int arr[300001];

int get_operation_len(vector<pair<char, int>>& v) {
    int len = 0;

    for (auto [c, d] : v) {
        len += d;
    }

    return len;
}

void print_operation(vector<pair<char, int>>& v) {
    for (auto [c, d] : v) {
        for (int i = 0; i < d; i++) {
            cout << c;
        }
    }

    cout << '\n';
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int left = 1;
    int right = n;

    while (arr[left] == 0) left++;
    while (arr[right] == 0) right--;

    vector<pair<char, int>> v1 = {{'R', n - (left - 1)}};
    vector<pair<char, int>> v2 = {{'L', right}};
    vector<pair<char, int>> mn = (get_operation_len(v2) < get_operation_len(v1) ? v2 : v1);

    while (left <= right) {
        if (arr[left] == 1) {
            left++;
            continue;
        }

        int new_right = left;

        while (new_right + 1 <= right && arr[new_right + 1] == 0) {
            new_right++;
        }

        vector<pair<char, int>> v3 = {{'L', left - 1}, {'R', (left - 1) + (n - new_right)}};
        vector<pair<char, int>> v4 = {{'R', (n - new_right)}, {'L', (left - 1) + (n - new_right)}};
        mn = (get_operation_len(v3) < get_operation_len(mn) ? v3 : mn);
        mn = (get_operation_len(v4) < get_operation_len(mn) ? v4 : mn);

        left = new_right + 1;
    }


    cout << get_operation_len(mn) << '\n';
    print_operation(mn);
    return 0;
}
