// Solve 2025-04-29

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

ll similar_finonacci[117];

void create_similar_finonacci() {
    similar_finonacci[3] = similar_finonacci[2] = similar_finonacci[1] = 1;

    for (int i = 4; i <= 116; i++) {
        similar_finonacci[i] = similar_finonacci[i - 1] + similar_finonacci[i - 3];
    }
}

int main() {
    FASTIO;

    create_similar_finonacci();

    int n;
    cin >> n;

    cout << similar_finonacci[n] << '\n';

    return 0;
}
