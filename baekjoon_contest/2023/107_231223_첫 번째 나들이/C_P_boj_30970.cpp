// Solve 2023-12-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Miniature{
    int quality, price;
};

istream& operator>>(istream &is, Miniature &rhs) {
    return is >> rhs.quality >> rhs.price;
}

ostream& operator<<(ostream &os, const Miniature &rhs) {
    return os << rhs.quality << ' ' << rhs.price;
}

bool cmp_quality_price(const Miniature &a, const Miniature &b) {
    if (a.quality != b.quality) return a.quality > b.quality;
    return a.price < b.price;
}

bool cmp_price_quality(const Miniature &a, const Miniature &b) {
    if (a.price != b.price) return a.price < b.price;
    return a.quality > b.quality;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Miniature> miniatures(n);

    for (Miniature &m : miniatures) {
        cin >> m;
    }

    sort(miniatures.begin(), miniatures.end(), cmp_quality_price);
    cout << miniatures[0] << ' ' << miniatures[1] << '\n';

    sort(miniatures.begin(), miniatures.end(), cmp_price_quality);
    cout << miniatures[0] << ' ' << miniatures[1] << '\n';

    return 0;
}
