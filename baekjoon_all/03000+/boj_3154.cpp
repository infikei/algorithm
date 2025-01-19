// Solve 2025-01-18

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

int get_manhattan_dist(pii &a, pii &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    FASTIO;

    vector<pii> keyboard = {
        { 3, 1 },
        { 0, 0 },
        { 0, 1 },
        { 0, 2 },
        { 1, 0 },
        { 1, 1 },
        { 1, 2 },
        { 2, 0 },
        { 2, 1 },
        { 2, 2 }
    };

    string hhmm;
    cin >> hhmm;

    int h = stoi(hhmm.substr(0, 2));
    int m = stoi(hhmm.substr(3, 2));

    int h2 = h;
    int m2 = m;
    int min_dist = 100;

    for (int i = h; i < 100; i += 24) {
        for (int j = m; j < 100; j += 60) {
            int dist = get_manhattan_dist(keyboard[i / 10], keyboard[i % 10])
                    + get_manhattan_dist(keyboard[i % 10], keyboard[j / 10])
                    + get_manhattan_dist(keyboard[j / 10], keyboard[j % 10]);

            if (dist < min_dist) {
                min_dist = dist;
                h2 = i;
                m2 = j;
            }
        }
    }

    setw(2, '0');
    cout << h2 << ':';
    setw(2, '0');
    println(m2);

    return 0;
}
