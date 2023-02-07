// Solve 2023-02-08

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

vector<string> make_triangle(int k) {
    if (k == 3) {
        return {"   ", "  *  ", " * * ", "*****"};
    }

    int k2 = k / 2;
    vector<string> small_triangle = make_triangle(k2);

    vector<string> triangle;
    triangle.push_back(small_triangle[0] + small_triangle[0]);
    for (int i = 1; i <= k2; i++) {
        triangle.push_back(small_triangle[0] + small_triangle[i] + small_triangle[0]);
    }
    for (int i = 1; i <= k2; i++) {
        triangle.push_back(small_triangle[i] + " " + small_triangle[i]);
    }
    return triangle;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> triangle = make_triangle(n);
    for (int i = 1; i <= n; i++) {
        cout << triangle[i] << '\n';
    }

    return 0;
}