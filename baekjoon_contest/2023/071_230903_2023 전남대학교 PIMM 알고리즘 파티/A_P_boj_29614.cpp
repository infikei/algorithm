// Solve 2023-09-03
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    cin >> s;

    int sum = 0;
    int cnt = 0;
    int pos = 0, pos_end = SIZE(s);

    while (pos < pos_end) {
        string w;
        w.push_back(s[pos]);

        if (pos + 1 < pos_end && s[pos + 1] == '+') {
            w.push_back(s[++pos]);
        }

        pos++;
        cnt++;

        if (w == "A+") sum += 45;
        else if (w == "A") sum += 40;
        else if (w == "B+") sum += 35;
        else if (w == "B") sum += 30;
        else if (w == "C+") sum += 25;
        else if (w == "C") sum += 20;
        else if (w == "D+") sum += 15;
        else if (w == "D") sum += 10;
    }

    double avg = sum * 0.1 / cnt;
    cout << avg << '\n';

    return 0;
}
