#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using uint = unsigned int;
using ull = unsigned long long;

uint N, L, X[100000];

int main() {
    fastio;

    cin >> N >> L;

    for (int n = 0; n < N; n++) {
        cin >> X[n];
    }

    ull W, sum_of_weight = 0, sum_of_product = 0;
    for (int n = 0; n < N; n++) {
        cin >> W;
        sum_of_weight += W;
        sum_of_product += W * (ull)X[n];
    }

    double ans = sum_of_product / (double)sum_of_weight;
    cout << fixed;
    cout.precision(9);
    cout << ans << '\n';

    return 0;
}