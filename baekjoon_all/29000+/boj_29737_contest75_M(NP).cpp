// Solve 2023-09-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct User{
    string handle = "";
    int streak_max_len = 0, streak_max_frz = 0, streak_max_date = 0, streak_fail = 0;

    bool operator<(const User &rhs) const {
        if (streak_max_len != rhs.streak_max_len) return streak_max_len > rhs.streak_max_len;
        if (streak_max_frz != rhs.streak_max_frz) return streak_max_frz < rhs.streak_max_frz;
        if (streak_max_date != rhs.streak_max_date) return streak_max_date < rhs.streak_max_date;
        if (streak_fail != rhs.streak_fail) return streak_fail < rhs.streak_fail;
        return handle < rhs.handle;
    }
};

int main() {
    FASTIO;

    int n, w;
    cin >> n >> w;

    vector<User> users;

    for (int i = 0; i < n; i++) {
        User user;
        cin >> user.handle;

        vector<string> streak(7, "");

        for (string &s : streak) {
            cin >> s;
        }

        int len = 0, frz = 0, date = 0;

        for (int col = 0; col < w; col++) {
            for (int row = 0; row < 7; row++) {
                char cur = streak[row][col];

                if (cur == 'X') {
                    user.streak_fail++;
                    len = 0; frz = 0;
                }
                else if (cur == 'F') {
                    frz++;
                }
                else {
                    if (++len == 1) {
                        frz = 0;
                        date = col * 7 + row + 1;
                    }

                    if (len > user.streak_max_len) {
                        user.streak_max_len = len;
                        user.streak_max_frz = frz;
                        user.streak_max_date = date;
                    }
                    else if (len == user.streak_max_len && frz < user.streak_max_frz) {
                        user.streak_max_frz = frz;
                        user.streak_max_date = date;
                    }
                }
            }
        }

        users.push_back(user);
    }

    sort(users.begin(), users.end());

    cout << "1. " << users[0].handle << '\n';

    for (int i = 1, ranking = 1, ie = SIZE(users); i < ie; i++) {
        if (users[i].streak_max_len != users[i - 1].streak_max_len) ranking++;
        else if (users[i].streak_max_frz != users[i - 1].streak_max_frz) ranking++;
        else if (users[i].streak_max_date != users[i - 1].streak_max_date) ranking++;
        else if (users[i].streak_fail != users[i - 1].streak_fail) ranking++;

        cout << ranking << ". " << users[i].handle << '\n';
    }

    return 0;
}
