// Solve 2023-08-22
// Update 2024-03-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string line;
        getline(cin, line);

        if (line == "") getline(cin, line);

        stringstream ss(line);
        string w;
        vector<int> num;
        vector<char> op;

        getline(ss, w, ' ');
        num.push_back(stoi(w));

        while (getline(ss, w, ' ')) {
            char new_op = w[0];
            getline(ss, w, ' ');
            int new_num = stoi(w);

            if (new_op == '*') {
                num.back() *= new_num;
            }
            else if (new_op == '/') {
                num.back() /= new_num;
            }
            else if (new_op == '%') {
                num.back() %= new_num;
            }
            else {
                op.push_back(new_op);
                num.push_back(new_num);
            }
        }

        int ans = num[0];

        for (int i = 1; i < SIZE(num); i++) {
            if (op[i - 1] == '+') {
                ans += num[i];
            }
            else {
                ans -= num[i];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
