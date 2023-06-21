// Solve 2023-06-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

char cube[6][9]; // U = 0, F = 1, D = 2, B = 3, L = 4, R = 5
char colors[6] = { 'w', 'r', 'y', 'o', 'g', 'b' };
char tmp[12];

int face_in_edges[8] = { 0, 1, 2, 5, 8, 7, 6, 3 };
pii face_out_edges[6][12] = { { { 3, 6 }, { 3, 7 }, { 3, 8 }, { 5, 2 }, { 5, 1 }, { 5, 0 },\
                                { 1, 2 }, { 1, 1 }, { 1, 0 }, { 4, 2 }, { 4, 1 }, { 4, 0 } },\
                              { { 0, 6 }, { 0, 7 }, { 0, 8 }, { 5, 0 }, { 5, 3 }, { 5, 6 },\
                                { 2, 2 }, { 2, 1 }, { 2, 0 }, { 4, 8 }, { 4, 5 }, { 4, 2 } },\
                              { { 3, 2 }, { 3, 1 }, { 3, 0 }, { 4, 6 }, { 4, 7 }, { 4, 8 },\
                                { 1, 6 }, { 1, 7 }, { 1, 8 }, { 5, 6 }, { 5, 7 }, { 5, 8 } },\
                              { { 0, 2 }, { 0, 1 }, { 0, 0 }, { 4, 0 }, { 4, 3 }, { 4, 6 },\
                                { 2, 6 }, { 2, 7 }, { 2, 8 }, { 5, 8 }, { 5, 5 }, { 5, 2 } },\
                              { { 0, 0 }, { 0, 3 }, { 0, 6 }, { 1, 0 }, { 1, 3 }, { 1, 6 },\
                                { 2, 0 }, { 2, 3 }, { 2, 6 }, { 3, 0 }, { 3, 3 }, { 3, 6 } },\
                              { { 3, 8 }, { 3, 5 }, { 3, 2 }, { 2, 8 }, { 2, 5 }, { 2, 2 },\
                                { 1, 8 }, { 1, 5 }, { 1, 2 }, { 0, 8 }, { 0, 5 }, { 0, 2 } } };

void cube_init() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube[i][j] = colors[i];
        }
    }
}

void cube_rotate(int face_idx, char direction) {
    // rotate edges inside the face

    int i = 0, j = 0;

    for (i = 0; i < 8; i++) {
        tmp[i] = cube[face_idx][face_in_edges[i]];
    }

    i = 0, j = 6;
    if (direction == '-') j = 2;
    while (i < 8) {
        cube[face_idx][face_in_edges[i]] = tmp[j];
        i++; j++;
        if (j == 8) j = 0;
    }

    // rotate edges outside the face

    for (i = 0; i < 12; i++) {
        tmp[i] = cube[face_out_edges[face_idx][i].first][face_out_edges[face_idx][i].second];
    }

    i = 0, j = 9;
    if (direction == '-') j = 3;
    while (i < 12) {
        cube[face_out_edges[face_idx][i].first][face_out_edges[face_idx][i].second] = tmp[j];
        i++; j++;
        if (j == 12) j = 0;
    }
}

void cube_print() {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 3; j++) {
            cout << cube[0][i + j];
        }
        cout << '\n';
    }
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        cube_init();

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            int face_idx = 0;
            if (s[0] == 'U') face_idx = 0;
            else if (s[0] == 'F') face_idx = 1;
            else if (s[0] == 'D') face_idx = 2;
            else if (s[0] == 'B') face_idx = 3;
            else if (s[0] == 'L') face_idx = 4;
            else face_idx = 5;

            cube_rotate(face_idx, s[1]);
        }

        cube_print();
    }

    return 0;
}
