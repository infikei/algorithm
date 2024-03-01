// Solve 2024-02-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    double max_val = 0;
    int max_idx = 0;

    for (int i = 0; i < 3; i++) {
        int price, weight;
        cin >> price >> weight;

        int weight10 = weight * 10;
        int price10 = price * 10;

        if (price10 >= 5000) {
            price10 -= 500;
        }

        double val = weight10 / (double)price10;

        if (val > max_val) {
            max_val = val;
            max_idx = i;
        }
    }

    string snu = "SNU";
    cout << snu[max_idx] << '\n';

    return 0;
}
