// Solve 2023-01-09
// Update 2023-08-27

// 백준 같은 문제 : 9506번 = 10181번

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        int n;
        cin >> n;

        if (n == -1) break;

        int sum = 0;
        queue<int> que;
        stack<int> stck;

        for (int i = 1, ie = sqrt(n); i <= ie; i++) {
            if (n % i == 0) {
                if (i == 1) {
                    sum += 1;
                    continue;
                }

                sum += i;
                que.push(i);

                int j = n / i;
                if (i == j) break;
                sum += j;
                stck.push(j);
            }
        }

        if (n == sum) {
            cout << n << " = 1";

            while (!que.empty()) {
                cout << " + " << que.front();
                que.pop();
            }

            while (!stck.empty()) {
                cout << " + " << stck.top();
                stck.pop();
            }

            cout << '\n';
        }
        else {
            cout << n << " is NOT perfect.\n";
        }
    }

    return 0;
}
