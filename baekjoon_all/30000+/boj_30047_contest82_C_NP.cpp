// Solve 2023-09-24

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

    vector<int> vec;

    for (char &c : s) {
        if (c == 'f') {
            vec.push_back(-2);
        }
        else if (c == 'g') {
            vec.push_back(-1);
        }
        else {
            vec.push_back(0);
        }

        int flag = 1;

        while (flag > 0) {
            flag = 0;

            while (SIZE(vec) >= 2 && vec[SIZE(vec) - 2] == -1 && vec[SIZE(vec) - 1] >= 0) {
                int x = vec.back();
                vec.pop_back();

                while (!vec.empty() && vec.back() == -1) {
                    vec.pop_back();
                    x++;
                }

                vec.push_back(x);

                flag++;
            }

            while (SIZE(vec) >= 3 && vec[SIZE(vec) - 3] == -2 && vec[SIZE(vec) - 2] >= 0 && vec[SIZE(vec) - 1] >= 0) {
                int x = min(vec[SIZE(vec) - 2], vec[SIZE(vec) - 1]);
                vec.pop_back();
                vec.pop_back();
                vec.pop_back();
                vec.push_back(x);

                flag++;
            }
        }
    }

    if (SIZE(vec) == 1 && vec.back() >= 0) {
        cout << vec.back() << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
