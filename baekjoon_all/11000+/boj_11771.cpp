// Solve 2025-04-04

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

    int n;
    cin >> n;

    char grille[10][10];

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> grille[x][y];
        }
    }

    string encrypted_message;
    cin >> encrypted_message;

    vector<string> board(n, string(n, '#'));
    int i = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (grille[x][y] == '.') {
                board[x][y] = encrypted_message[i];
                i++;
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (grille[n - 1 - y][x] == '.') {
                if (board[x][y] != '#') {
                    cout << "invalid grille" << '\n';
                    return 0;
                }

                board[x][y] = encrypted_message[i];
                i++;
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (grille[n - 1 - x][n - 1 - y] == '.') {
                if (board[x][y] != '#') {
                    cout << "invalid grille" << '\n';
                    return 0;
                }

                board[x][y] = encrypted_message[i];
                i++;
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (grille[y][n - 1 - x] == '.') {
                if (board[x][y] != '#') {
                    cout << "invalid grille" << '\n';
                    return 0;
                }

                board[x][y] = encrypted_message[i];
                i++;
            }
        }
    }

    if (i != n * n) {
        cout << "invalid grille" << '\n';
        return 0;
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cout << board[x][y];
        }
    }

    cout << '\n';

    return 0;
}
