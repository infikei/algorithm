#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, ans;
priority_queue<int> PQ_max;

void solve() {
    while ((int)(PQ_max.size()) > 2) {
        int a = PQ_max.top();
        PQ_max.pop();
        int b = PQ_max.top();
        PQ_max.pop();
        int tmp = b - PQ_max.top() / 2;
        a -= tmp;
        b -= tmp;
        ans += tmp;
        
        if (b > 0) {
            PQ_max.push(b);
        }
        if (a > 0) {
            PQ_max.push(a);
        }
    }

    if ((int)(PQ_max.size()) == 2) {
        int a = PQ_max.top();
        PQ_max.pop();
        ans += max(a, PQ_max.top());
    }
    else if ((int)(PQ_max.size()) == 1) {
        ans += PQ_max.top();
    }
}

int main() {
    fastio;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        PQ_max.push(x);
    }

    solve();

    if (ans > 1440) {
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}