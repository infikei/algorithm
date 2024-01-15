// Solve 2024-01-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string king, stone;
    int n;
    cin >> king >> stone >> n;

    for (int i = 0; i < n; i++) {
        string move;
        cin >> move;

        string nxt_king = king;
        string nxt_stone = stone;

        if (move == "R") {
            if (++nxt_king[0] > 'H') {
                continue;
            }

            if (nxt_king == stone) {
                if (++nxt_stone[0] > 'H') {
                    continue;
                }
            }
        }
        else if (move == "L") {
            if (--nxt_king[0] < 'A') {
                continue;
            }

            if (nxt_king == stone) {
                if (--nxt_stone[0] < 'A') {
                    continue;
                }
            }
        }
        else if (move == "B") {
            if (--nxt_king[1] < '1') {
                continue;
            }

            if (nxt_king == stone) {
                if (--nxt_stone[1] < '1') {
                    continue;
                }
            }
        }
        else if (move == "T") {
            if (++nxt_king[1] > '8') {
                continue;
            }

            if (nxt_king == stone) {
                if (++nxt_stone[1] > '8') {
                    continue;
                }
            }
        }
        else if (move == "RT") {
            if (++nxt_king[0] > 'H') {
                continue;
            }

            if (++nxt_king[1] > '8') {
                continue;
            }

            if (nxt_king == stone) {
                if (++nxt_stone[0] > 'H') {
                    continue;
                }

                if (++nxt_stone[1] > '8') {
                    continue;
                }
            }
        }
        else if (move == "LT") {
            if (--nxt_king[0] < 'A') {
                continue;
            }

            if (++nxt_king[1] > '8') {
                continue;
            }

            if (nxt_king == stone) {
                if (--nxt_stone[0] < 'A') {
                    continue;
                }

                if (++nxt_stone[1] > '8') {
                    continue;
                }
            }
        }
        else if (move == "RB") {
            if (++nxt_king[0] > 'H') {
                continue;
            }

            if (--nxt_king[1] < '1') {
                continue;
            }

            if (nxt_king == stone) {
                if (++nxt_stone[0] > 'H') {
                    continue;
                }

                if (--nxt_stone[1] < '1') {
                    continue;
                }
            }
        }
        else if (move == "LB") {
            if (--nxt_king[0] < 'A') {
                continue;
            }

            if (--nxt_king[1] < '1') {
                continue;
            }

            if (nxt_king == stone) {
                if (--nxt_stone[0] < 'A') {
                    continue;
                }

                if (--nxt_stone[1] < '1') {
                    continue;
                }
            }
        }

        king = nxt_king;
        stone = nxt_stone;
    }

    cout << king << '\n';
    cout << stone << '\n';

    return 0;
}
