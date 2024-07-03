// Solve 2023-05-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

char from[7] = { '@', '[', '!', ';', '^', '0', '7' };
char to[7] = { 'a', 'c', 'i', 'j', 'n', 'o', 't' };

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int ni = 0; ni < n; ni++) {
        string s, ans;
        cin >> s;

        int cnt = 0;

        for (int i = 0; i < SIZE(s); i++) {
            bool flag = false;
            for (int j = 0; j < 7; j++) {
                if (s[i] == from[j]) {
                    ans.push_back(to[j]);
                    cnt++;
                    flag = true;
                    break;
                }
            }
            if (flag) continue;

            if (s[i] == '\\') {
                if (s[i + 1] == '\'') {
                    ans.push_back('v');
                    i++;
                    cnt++;
                }
                else {
                    ans.push_back('w');
                    i += 2;
                    cnt++;
                }
            }
            else {
                ans.push_back(s[i]);
            }
        }

        if (cnt * 2 >= SIZE(ans)) {
            cout << "I don\'t understand\n";
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}
