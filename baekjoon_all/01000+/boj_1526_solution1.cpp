// Solve 2023-12-31
// Update 2025-03-03

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

void dfs(int depth, int cur_num, vector<int> &four_seven_numbers) {
    if (depth >= 7) return;

    int nxt_num = cur_num * 10 + 4;
    four_seven_numbers.push_back(nxt_num);
    dfs(depth + 1, nxt_num, four_seven_numbers);

    nxt_num += 3;
    four_seven_numbers.push_back(nxt_num);
    dfs(depth + 1, nxt_num, four_seven_numbers);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> four_seven_numbers;

    dfs(1, 0, four_seven_numbers);

    sort(four_seven_numbers.begin(), four_seven_numbers.end());

    auto it = upper_bound(four_seven_numbers.begin(), four_seven_numbers.end(), n);
    it--;

    cout << *it << '\n';

    return 0;
}
