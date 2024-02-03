// Solve 2023-03-29
// Update 2024-02-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n, s, ans;
int arr[20];

void recur(int depth = 0, int sum = 0, int cnt = 0) {
    if (depth == n) {
        if (sum == s && cnt > 0) {
            ans++;
        }

        return;
    }

    recur(depth + 1, sum, cnt);
    recur(depth + 1, sum + arr[depth], cnt + 1);
}

int main() {
    FASTIO;

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    recur();

    cout << ans << '\n';

    return 0;
}
