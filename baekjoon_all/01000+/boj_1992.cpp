// Solve 2022-12-06
// Update 2023-02-08

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int n;
string input_data[64];

string make_output_data(int row, int col, int size) {
    string res;
    if (size == 1) {
        res = input_data[row][col];
        return res;
    }

    int nsize = size / 2;
    res = make_output_data(row, col, nsize);
    res += make_output_data(row, col + nsize, nsize);
    res += make_output_data(row + nsize, col, nsize);
    res += make_output_data(row + nsize, col + nsize, nsize);

    if (res == "1111") {
        return "1";
    }
    if (res == "0000") {
        return "0";
    }
    return "(" + res + ")";
}

int main() {
    FASTIO;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input_data[i];
    }

    string output_data = make_output_data(0, 0, n);
    cout << output_data;

    return 0;
}