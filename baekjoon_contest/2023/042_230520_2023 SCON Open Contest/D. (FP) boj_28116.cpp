// Solve 2023-05-21

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int numbers[500001];
int numbers_idx[500001];
int ans[500001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> numbers[i];
        numbers_idx[numbers[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        int num_i = numbers[i];
        int j = numbers_idx[i];
        numbers[j] = num_i;
        numbers_idx[num_i] = j;
        ans[num_i] += abs(j - i);
        ans[i] += abs(j - i);

        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
