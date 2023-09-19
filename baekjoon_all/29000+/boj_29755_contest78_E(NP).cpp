// Solve 2023-09-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Asteroid{
    int a = 0, w = 1;
    bool operator<(const Asteroid &rhs) const {
        return a < rhs.a;
    }
};

struct Black_hole{
    int b = 0;
    bool operator<(const Black_hole &rhs) const {
        return b < rhs.b;
    }
};

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<Black_hole> black_holes(n);
    vector<Asteroid> asteroids(m);

    for (Black_hole &x : black_holes) {
        cin >> x.b;
    }

    sort(black_holes.begin(), black_holes.end());

    for (Asteroid &x : asteroids) {
        cin >> x.a >> x.w;
    }

    sort(asteroids.begin(), asteroids.end());

    int p = 0;
    int i = 0, j = 0, ie = SIZE(black_holes), je = SIZE(asteroids);

    while (j < je && asteroids[j].a < black_holes[0].b) {
        int cur = abs(black_holes[0].b - asteroids[j].a) * asteroids[j].w;
        p = max(p, cur);

        j++;
    }

    while (i + 1 < ie) {
        while (j < je && asteroids[j].a < black_holes[i + 1].b) {
            int cur = min(abs(black_holes[i].b - asteroids[j].a), abs(black_holes[i + 1].b - asteroids[j].a)) * asteroids[j].w;
            p = max(p, cur);

            j++;
        }

        i++;
    }

    while (j < je) {
        int cur = abs(black_holes[i].b - asteroids[j].a) * asteroids[j].w;
        p = max(p, cur);

        j++;
    }

    cout << p << '\n';

    return 0;
}
