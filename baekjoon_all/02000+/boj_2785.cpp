// Solve 2024-04-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> chains(n);

    for (int &x : chains) {
        cin >> x;
    }

    sort(chains.begin(), chains.end());

    int idx = 0;
    int cnt = 0;

    while (idx + 1 < SIZE(chains)) {
        cnt++;

        if (idx + 2 < SIZE(chains)) {
            chains.pop_back();

            if (--chains[idx] == 0) {
                idx++;
            }
        }
        else {
            chains[idx++] = 0;
        }
    }

    cout << cnt << '\n';

    return 0;
}
