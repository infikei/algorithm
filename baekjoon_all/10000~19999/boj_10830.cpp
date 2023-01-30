#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;
using vvint = vector<vector<int> >;

int N;
ll B;
vvint A, ans;

vvint mat_mul(vvint m1, vvint m2, int mod = 1000) {
    vvint res(N, vector<int>(N, 0));

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            for (int iter = 0; iter < N; iter++) {
                res[row][col] += m1[row][iter] * m2[iter][col];
            }
            res[row][col] %= mod;
        }
    }

    return res;
}

vvint mat_power(vvint m, ll n) {
    if (n == 1) {
        return m;
    }

    vvint k = mat_power(m, n / 2);
    if (n % 2 == 0) {
        return mat_mul(k, k);
    }
    else {
        return mat_mul(mat_mul(k, k), m);
    }
}

void input() {
    cin >> N >> B;

    for (int row = 0; row < N; row++) {
        vector<int> A_row(N, 0);
        for (int col = 0; col < N; col++) {
            cin >> A_row[col];
        }
        A.push_back(A_row);
    }
}

void solve() {
    ans = mat_power(A, B);

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            ans[row][col] %= 1000;
        }
    }
}

void print() {
    for (auto v : ans) {
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int main() {
    fastio;

    input();

    solve();

    print();

    return 0;
}