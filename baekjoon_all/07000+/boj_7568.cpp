// Solve 2023-10-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> kg(n), cm(n);

    for (int i = 0; i < n; i++) {
        cin >> kg[i] >> cm[i];
    }

    vector<int> rank(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (kg[i] > kg[j] && cm[i] > cm[j]) {
                rank[j]++;
            }
            else if (kg[i] < kg[j] && cm[i] < cm[j]) {
                rank[i]++;
            }
        }
    }

    for (int &x : rank) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}
