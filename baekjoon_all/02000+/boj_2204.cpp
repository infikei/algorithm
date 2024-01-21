// Solve 2024-01-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct cmp_word{
    bool operator()(string a, string b) {
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        return a < b;
    }
};

int main() {
    FASTIO;

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        vector<string> words(n);

        for (string &word : words) {
            cin >> word;
        }

        sort(words.begin(), words.end(), cmp_word());

        cout << words[0] << '\n';
    }

    return 0;
}
