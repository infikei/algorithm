// Solve 2023-10-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Player{
    int country, idx, score;
    bool operator<(const Player &rhs) const {
        return score > rhs.score;
    }
};

istream& operator>>(istream &is, Player &rhs) {
    return is >> rhs.country >> rhs.idx >> rhs.score;
}

ostream& operator<<(ostream &os, const Player &rhs) {
    return os << rhs.country << ' ' << rhs.idx;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    Player players[100];

    for (int i = 0; i < n; i++) {
        cin >> players[i];
    }

    sort(players, players + n);

    int country_cnt[101] = { 0 };

    cout << players[0] << '\n';
    country_cnt[players[0].country]++;

    cout << players[1] << '\n';
    country_cnt[players[1].country]++;

    int pos = 2;

    while (country_cnt[players[pos].country] == 2) {
        pos++;
    }

    cout << players[pos] << '\n';

    return 0;
}
