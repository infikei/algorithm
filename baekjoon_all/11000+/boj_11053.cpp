// Solve 2022-07-09
// Update 2024-12-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int arr[1000];
int memo[1000];

int get_lis(int n) {
    for (int i = 0; i < n; i++) {
        memo[i] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }
    }

    return *max_element(memo, memo + n);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    println(get_lis(n));

    return 0;
}
