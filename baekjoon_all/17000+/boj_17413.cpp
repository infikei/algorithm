// Solve 2023-02-22

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
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    string line;
    getline(cin, line);

    int i_end = SIZE(line);
    for (int i = 0; i < i_end; i++) {
        if (line[i] == '<') {
            i++;
            while (line[i] != '>') {
                i++;
            }
        }
        else if (line[i] == ' ') {
            continue;
        }
        else {
            int j = i;
            while (j < i_end && line[j] != ' ' && line[j] != '<') {
                j++;
            }
            reverse(line.begin() + i, line.begin() + j);
            i = j;
            i--;
        }
    }

    cout << line << '\n';

    return 0;
}