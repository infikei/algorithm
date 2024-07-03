// Solve 2023-09-24
// Update 2023-12-25

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

        bool while_flag = true;

        while (while_flag) {
            while_flag = false;

            while (SIZE(vec) >= 2 && vec[SIZE(vec) - 2] == -1 && vec[SIZE(vec) - 1] >= 0) {
                int val = vec.back();
                vec.pop_back();

                while (!vec.empty() && vec.back() == -1) {
                    vec.pop_back();
                    val++;
                }

                vec.push_back(val);
                while_flag = true;
            }

            while (SIZE(vec) >= 3 && vec[SIZE(vec) - 3] == -2 && vec[SIZE(vec) - 2] >= 0 && vec[SIZE(vec) - 1] >= 0) {
                int val = min(vec[SIZE(vec) - 2], vec[SIZE(vec) - 1]);
                vec.pop_back();
                vec.pop_back();
                vec.pop_back();
                vec.push_back(val);
                while_flag = true;
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
