// Solve 2023-10-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int milk, honey, n;
    cin >> milk >> honey >> n;

    int happiness = 0;

    for (int i = 0; i < n; i++) {
        int cows, bees;
        cin >> cows >> bees;

        happiness += max(cows * milk, bees * honey);
    }

    cout << happiness << '\n';

    return 0;
}
