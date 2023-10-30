// Solve 2023-10-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int alphabet_num[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

    string a, b;
    cin >> a >> b;

    vector<int> vec(SIZE(a) * 2, 0);

    for (int i = 0; i < SIZE(a); i++) {
        vec[i * 2] = alphabet_num[a[i] - 'A'];
    }

    for (int i = 0; i < SIZE(b); i++) {
        vec[i * 2 + 1] = alphabet_num[b[i] - 'A'];
    }

    while (SIZE(vec) > 2) {
        for (int i = 1; i < SIZE(vec); i++) {
            vec[i - 1] = (vec[i - 1] + vec[i]) % 10;
        }

        vec.pop_back();
    }

    cout << vec[0] << vec[1] << '\n';

    return 0;
}
