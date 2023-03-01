// Solve 2022-06-05
// Update 2023-03-01

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int q_begin = 0, q_end = 0;
int q[10001];

void push(int x) {
    q[q_end] = x;
    q_end++;
}

int pop() {
    if (q_begin == q_end) {
        return -1;
    }
    q_begin++;
    return q[q_begin - 1];
}

int size() {
    return q_end - q_begin;
}

int empty() {
    if (q_begin == q_end) {
        return 1;
    }
    return 0;
}

int front() {
    if (q_begin == q_end) {
        return -1;
    }
    return q[q_begin];
}

int back() {
    if (q_begin == q_end) {
        return -1;
    }
    return q[q_end - 1];
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            push(x);
        }
        else if (cmd == "pop") {
            cout << pop() << '\n';
        }
        else if (cmd == "size") {
            cout << size() << '\n';
        }
        else if (cmd == "empty") {
            cout << empty() << '\n';
        }
        else if (cmd == "front") {
            cout << front() << '\n';
        }
        else {
            cout << back() << '\n';
        }
    }

    return 0;
}