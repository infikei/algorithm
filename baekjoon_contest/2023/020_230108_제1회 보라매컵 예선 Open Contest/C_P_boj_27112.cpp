// Solve 2023-01-08
// Update 2023-12-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Task{
    int d, t;

    Task(int d, int t) : d(d), t(t) {}

    bool operator<(const Task &rhs) const {
        if (d != rhs.d) return d > rhs.d;
        return t > rhs.t;
    }
};

int calc_normal_work(int d) {
    return (d - 1) / 7 * 5 + min(5, (d - 1) % 7 + 1);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    priority_queue<Task, vector<Task>> pq_mintop;

    for (int i = 0; i < n; i++) {
        int d, t;
        cin >> d >> t;
        pq_mintop.emplace(d, t);
    }

    int ans = 0;
    bool check = true;
    int day = 0;
    int normal_work = 0;
    int overtime_work = 0;
    int prev_normal_work = 0;

    while (!pq_mintop.empty()) {
        Task cur_task = pq_mintop.top();
        pq_mintop.pop();

        int cur_normal_work = calc_normal_work(cur_task.d);
        normal_work += cur_normal_work - prev_normal_work;
        prev_normal_work = cur_normal_work;
        overtime_work += cur_task.d - day;
        day = cur_task.d;
        normal_work -= cur_task.t;

        if (normal_work < 0) {
            overtime_work += normal_work;
            ans -= normal_work;
            normal_work = 0;

            if (overtime_work < 0) {
                check = false;
                break;
            }
        }
    }

    cout << (check ? ans : -1) << '\n';

    return 0;
}
