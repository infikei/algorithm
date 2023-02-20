// Solve 2023-02-19

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

deque<char> dq;
deque<int> dq_idx;
int dq_size;

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            char ch;
            cin >> ch;
            dq.push_back(ch);
            dq_idx.push_back(dq_size);
            dq_size++;
        }
        else if (cmd == 2) {
            char ch;
            cin >> ch;
            dq.push_front(ch);
            dq_idx.push_front(dq_size);
            dq_size++;
        }
        else {
            if (dq.empty()) continue;
            if (dq_idx.front() < dq_idx.back()) {
                dq.pop_back();
                dq_idx.pop_back();
                dq_size--;
            }
            else {
                dq.pop_front();
                dq_idx.pop_front();
                dq_size--;
            }
        }
    }

    if (dq.empty()) {
        cout << 0 << '\n';
    }
    else {
        for (auto ch : dq) {
            cout << ch;
        }
        cout << '\n';
    }

    return 0;
}