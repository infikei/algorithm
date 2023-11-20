// Solve 2022-12-27
// Update 2023-11-20

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
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string handle;
        getline(cin, handle);

        stringstream ss(handle);
        string word;
        getline(ss, word, ' ');
        string result = "god";

        while (getline(ss, word, ' ')) {
            result += word;
        }

        cout << result << '\n';
    }

    return 0;
}
