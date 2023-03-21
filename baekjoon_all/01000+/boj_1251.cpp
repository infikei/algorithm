// Solve 2023-03-20

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    string word;
    cin >> word;

    int n = SIZE(word);

    string ans;
    ans.assign(n, 'z');

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string new_word = word;
            reverse(new_word.begin(), new_word.begin() + i);
            reverse(new_word.begin() + i, new_word.begin() + j);
            reverse(new_word.begin() + j, new_word.end());
            if (new_word < ans) {
                ans = new_word;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
