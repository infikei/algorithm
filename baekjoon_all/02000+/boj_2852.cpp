// Solve 2025-06-06

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

    int cur_time = 0;
    int score[3] = {0, 0, 0};
    int winning_time[3] = {0, 0, 0};

    while (n-- > 0) {
        int team;
        string mmss;
        cin >> team >> mmss;

        int score_min = stoi(mmss.substr(0, 2));
        int score_sec = stoi(mmss.substr(3, 2));
        int score_time = score_min * 60 + score_sec;

        if (score[1] > score[2]) {
            winning_time[1] += score_time - cur_time;
        }
        else if (score[1] < score[2]) {
            winning_time[2] += score_time - cur_time;
        }

        cur_time = score_time;
        score[team]++;
    }

    if (score[1] > score[2]) {
        winning_time[1] += 48 * 60 - cur_time;
    }
    else if (score[1] < score[2]) {
        winning_time[2] += 48 * 60 - cur_time;
    }

    SETW(2, '0');
    cout << winning_time[1] / 60 << ':';
    SETW(2, '0');
    cout << winning_time[1] % 60 << '\n';
    SETW(2, '0');
    cout << winning_time[2] / 60 << ':';
    SETW(2, '0');
    cout << winning_time[2] % 60 << '\n';

    return 0;
}
