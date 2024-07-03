// Solve 2024-01-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

void hanoi_3(int depth, char begin, char end) {
    if (depth == 1) {
        cout << begin << ' ' << end << '\n';
        return;
    }

    char mid;

    if (begin == 'A' || end == 'A') {
        if (begin == 'B' || end == 'B') {
            mid = 'C';
        }
        else {
            mid = 'B';
        }
    }
    else {
        mid = 'A';
    }

    hanoi_3(depth - 1, begin, mid);
    cout << begin << ' ' << end << '\n';
    hanoi_3(depth - 1, mid, end);
}

void hanoi_4(int depth, char begin, char end) {
    if (depth == 1) {
        cout << begin << ' ' << end << '\n';
        return;
    }
    else if (depth == 2) {
        char mid = 'A';

        if (begin == 'A') {
            mid = 'B';
        }

        cout << begin << ' ' << mid << '\n';
        cout << begin << ' ' << end << '\n';
        cout << mid << ' ' << end << '\n';
        return;
    }

    char mid1, mid2;

    if (begin == 'A') {
        mid1 = 'B';
        mid2 = 'C';
    }
    else if (begin == 'B') {
        mid1 = 'A';
        mid2 = 'C';
    }
    else {
        mid1 = 'A';
        mid2 = 'B';
    }

    hanoi_3(depth - 2, begin, mid1);
    cout << begin << ' ' << mid2 << '\n';
    cout << begin << ' ' << end << '\n';
    cout << mid2 << ' ' << end << '\n';
    hanoi_4(depth - 2, mid1, end);
}

int main() {
    FASTIO;

    int d[21] = { 0, 1, 3 };

    for (int i = 3; i <= 20; i++) {
        d[i] = 3 + d[i - 2] + (1 << (i - 2)) - 1;
    }

    int n;
    cin >> n;

    cout << d[n] << '\n';

    hanoi_4(n, 'A', 'D');

    return 0;
}
