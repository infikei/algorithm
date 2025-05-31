// Solve 2025-05-25

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int a[13][3] = {
    { 200, 210, 220 },
    { 210, 220, 225 },
    { 220, 225, 230 },
    { 225, 230, 235 },
    { 230, 235, 245 },
    { 235, 245, 250 },
    { 260, 265, 270 },
    { 265, 270, 275 },
    { 270, 275, 280 },
    { 275, 280, 285 },
    { 280, 285, 290 },
    { 285, 290, 295 },
    { 290, 295, 300 }
};

int main() {
    FASTIO;

    int l;
    cin >> l;

    for (int i = 0; i < 6; i++) {
        cout << (l >= a[i][2] ? 100 : l >= a[i][1] ? 300 : l >= a[i][0] ? 500 : 0) << ' ';
    }

    cout << '\n';

    for (int i = 6; i < 13; i++) {
        cout << (l >= a[i][2] ? 100 : l >= a[i][1] ? 300 : l >= a[i][0] ? 500 : 0) << ' ';
    }

    cout << '\n';

    return 0;
}
