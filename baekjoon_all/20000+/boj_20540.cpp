// Solve 2023-12-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string mbti;
    cin >> mbti;

    string ans;

    if (mbti[0] == 'E') ans.push_back('I');
    else ans.push_back('E');

    if (mbti[1] == 'S') ans.push_back('N');
    else ans.push_back('S');

    if (mbti[2] == 'T') ans.push_back('F');
    else ans.push_back('T');

    if (mbti[3] == 'J') ans.push_back('P');
    else ans.push_back('J');

    cout << ans << '\n';

    return 0;
}
