// Solve 2022-06-06
// Update 2023-06-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dq[10001];
int dq_begin = 0, dq_end = 0;

void push_front(int x) {
    dq_begin--;
    if (dq_begin < 0) {
        dq_begin += 10001;
    }
    dq[dq_begin] = x;
}

void push_back(int x) {
    dq[dq_end] = x;
    dq_end++;
    if (dq_end >= 10001) {
        dq_end -= 10001;
    }
}

int pop_front() {
    if (dq_begin == dq_end) {
        return -1;
    }
    dq_begin++;
    if (dq_begin >= 10001) {
        dq_begin -= 10001;
        return dq[10001 - 1];
    }
    return dq[dq_begin - 1];
}

int pop_back() {
    if (dq_begin == dq_end) {
        return -1;
    }
    dq_end--;
    if (dq_end < 0) {
        dq_end += 10001;
    }
    return dq[dq_end];
}

int size() {
    if (dq_begin <= dq_end) {
        return dq_end - dq_begin;
    }
    return dq_end - dq_begin + 10001;
}

int empty() {
    if (dq_begin == dq_end) {
        return 1;
    }
    return 0;
}

int front() {
    if (dq_begin == dq_end) {
        return -1;
    }
    return dq[dq_begin];
}

int back() {
    if (dq_begin == dq_end) {
        return -1;
    }
    if (dq_end == 0) {
        return dq[10001 - 1];
    }
    return dq[dq_end - 1];
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push_front") {
            int x;
            cin >> x;
            push_front(x);
        }
        else if (cmd == "push_back") {
            int x;
            cin >> x;
            push_back(x);
        }
        else if (cmd == "pop_front") {
            cout << pop_front() << '\n';
        }
        else if (cmd == "pop_back") {
            cout << pop_back() << '\n';
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
