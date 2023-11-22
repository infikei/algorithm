// Solve 2022-11-04
// Update 2023-11-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Pair{
    int num, prize;
    Pair(int num, int prize) : num(num), prize(prize) {}
};

int main() {
    FASTIO;

    Pair aa[7] = {
        { 0, 0 },
        { 1, 5000000 },
        { 3, 3000000 },
        { 6, 2000000 },
        { 10, 500000 },
        { 15, 300000 },
        { 21, 100000 }
    };

    Pair bb[6] = {
        { 0, 0 },
        { 1, 5120000 },
        { 3, 2560000 },
        { 7, 1280000 },
        { 15, 640000 },
        { 31, 320000 }
    };

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int a, b;
        cin >> a >> b;

        int prize_sum = 0;

        for (int i = 0; i < 7; i++) {
            if (a <= aa[i].num) {
                prize_sum += aa[i].prize;
                break;
            }
        }

        for (int i = 0; i < 6; i++) {
            if (b <= bb[i].num) {
                prize_sum += bb[i].prize;
                break;
            }
        }

        cout << prize_sum << '\n';
    }

    return 0;
}
