// Solve 2023-11-21
// Update 2025-03-02

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

    string max_name;
    int max_score = 0;

    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;

        if (score > max_score) {
            max_score = score;
            max_name = name;
        }
        else if (score == max_score && name < max_name) {
            max_name = name;
        }
    }

    cout << max_name << '\n';

    return 0;
}
