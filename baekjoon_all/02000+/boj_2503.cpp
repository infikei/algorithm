// Solve 2023-10-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Query{
    string num;
    int strike, ball;
};

istream& operator>>(istream &is, Query &rhs) {
    return is >> rhs.num >> rhs.strike >> rhs.ball;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    Query queries[100];

    for (int ni = 0; ni < n; ni++) {
        cin >> queries[ni];
    }

    string my_num = "000";
    int ans = 0;

    for (my_num[0] = '1'; my_num[0] <= '9'; my_num[0]++) {
        for (my_num[1] = '1'; my_num[1] <= '9'; my_num[1]++) {
            if (my_num[1] == my_num[0]) continue;

            for (my_num[2] = '1'; my_num[2] <= '9'; my_num[2]++) {
                if (my_num[2] == my_num[0] || my_num[2] == my_num[1]) continue;

                bool flag = true;

                for (int ni = 0; ni < n; ni++) {
                    int strike = 0, ball = 0;

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            if (my_num[i] == queries[ni].num[j]) {
                                if (j == i) strike++;
                                else ball++;
                            }
                        }
                    }

                    if (strike != queries[ni].strike || ball != queries[ni].ball) {
                        flag = false;
                        break;
                    }
                }

                if (flag) ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
