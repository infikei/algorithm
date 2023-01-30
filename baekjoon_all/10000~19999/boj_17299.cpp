#include <iostream>
#include <stack>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, A[1000000], F[1000001], NGF[1000000];
stack<int> stck;

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        F[A[i]]++;
    }
}

void solve() {
    for (int i = N - 1; i >= 0; i--) {
        while (!stck.empty() && F[A[i]] >= F[stck.top()]) {
            stck.pop();
        }

        if (stck.empty()) {
            NGF[i] = -1;
        }
        else {
            NGF[i] = stck.top();
        }
        stck.push(A[i]);
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        cout << NGF[i] << ' ';
    }
    cout << '\n';
}

int main() {
    fastio;

    input();

    solve();

    print();

    return 0;
}