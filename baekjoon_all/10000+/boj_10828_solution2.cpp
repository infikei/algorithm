// Solve 2022-06-04
// Update 2023-03-17

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

int stck[10001];
int stck_size = 0;

void push(int x) {
    stck[stck_size] = x;
    stck_size++;
}

int pop() {
    if (stck_size == 0)
        return -1;
    stck_size--;
    return stck[stck_size];
}

int size() {
    return stck_size;
}

int empty() {
    if (stck_size == 0) {
        return 1;
    }
    return 0;
}

int top() {
    if (stck_size == 0) {
        return -1;
    }
    return stck[stck_size - 1];
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
        else {
            cout << top() << '\n';
        }
    }

    return 0;
}
