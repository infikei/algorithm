// Solve 2023-02-20

#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int practice_sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        practice_sum += x;
    }

    if (practice_sum == 0) {
        cout << "divide by zero\n";
    }
    else {
        cout << "1.00\n";
    }

    return 0;
}