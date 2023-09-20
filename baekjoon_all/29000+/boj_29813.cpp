// Solve 2023-09-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Teammate{
    string name = "";
    int x = 1;
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    queue<Teammate> teammates;

    for (int i = 0; i < n; i++) {
        Teammate t;
        cin >> t.name >> t.x;

        teammates.push(t);
    }

    int iter = n / 2;

    while (--iter >= 0) {
        Teammate front = teammates.front();
        teammates.pop();

        int iter2 = front.x - 1;

        while (--iter2 >= 0) {
            teammates.push(teammates.front());
            teammates.pop();
        }

        teammates.pop();
    }

    cout << teammates.front().name << '\n';

    return 0;
}
