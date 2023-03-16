// Solve 2023-03-15

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    int files[50];
    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }

    int size_of_cluster;
    cin >> size_of_cluster;

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += files[i] / size_of_cluster;
        if (files[i] % size_of_cluster != 0) {
            cnt++;
        }
    }
    cout << cnt * size_of_cluster << '\n';

    return 0;
}
