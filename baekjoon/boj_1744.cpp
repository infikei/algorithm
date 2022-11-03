#include <iostream>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, ans;
int cnt_one = 0;
bool exist_zero = false;
priority_queue<int> pq_max; // 최댓값이 top에 있는 우선순위 큐
priority_queue<int, vector<int>, greater<int> > pq_min; // 최솟값이 top에 있는 우선순위 큐

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x > 1) {
            pq_max.push(x);
        }
        else if (x < 0) {
            pq_min.push(x);
        }
        else if (x == 1) {
            cnt_one++;
        }
        else {
            exist_zero = true;
        }
    }
}

void solve() {
    ans = 0;
    while (!pq_max.empty()) {
        int a = pq_max.top();
        pq_max.pop();

        if (!pq_max.empty()) {
            int b = pq_max.top();
            pq_max.pop();
            ans += a * b;
        }
        else {
            ans += a;
        }
    }
    while (!pq_min.empty()) {
        int a = pq_min.top();
        pq_min.pop();

        if (!pq_min.empty()) {
            int b = pq_min.top();
            pq_min.pop();
            ans += a * b;
        }
        else {
            if (!exist_zero) {
                ans += a;
            }
        }
    }
    ans += cnt_one;
}

int main() {
    fastio;

    input();

    solve();

    cout << ans << '\n';

    return 0;
}