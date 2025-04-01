// Solve 2025-03-30

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

int main() {
    FASTIO;

    int purple[6];

    for (int i = 0; i < 6; i++) {
        cin >> purple[i];
    }

    int r, g, b;
    cin >> r >> g >> b;

    int max_rgb = max(r, max(g, b));
    int min_rgb = min(r, min(g, b));
    int v = max_rgb;
    double s = 255 * (v - min_rgb) / (double) v;
    double h;

    if (v == r) {
        h = 60 * (g - b) / (double) (v - min_rgb);
    }
    else if (v == g) {
        h = 120 + 60 * (b - r) / (double) (v - min_rgb);
    }
    else {
        h = 240 + 60 * (r - g) / (double) (v - min_rgb);
    }

    if (h < 0) {
        h += 360;
    }

    if (purple[0] <= h && h <= purple[1] && purple[2] <= s && s <= purple[3] && purple[4] <= v && v <= purple[5]) {
        cout << "Lumi will like it." << '\n';
    }
    else {
        cout << "Lumi will not like it." << '\n';
    }

    return 0;
}
