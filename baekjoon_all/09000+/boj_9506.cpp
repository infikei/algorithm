#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    while (true) {
        int N;
        cin >> N;
        if (N == -1) {
            break;
        }

        int sum = 0;
        queue<int> q;
        stack<int> stck;

        for (int i = 1; i <= sqrt(N); i++) {
            if (N % i == 0) {
                if (i == 1) {
                    sum += 1;
                    continue;
                }
                sum += i;
                q.push(i);
                if (i == N / i) {
                    break;
                }
                sum += N / i;
                stck.push(N / i);
            }
        }

        if (N == sum) {
            cout << N << " = 1";
            while (!q.empty()) {
                cout << " + " << q.front();
                q.pop();
            }
            while (!stck.empty()) {
                cout << " + " << stck.top();
                stck.pop();
            }
            cout << '\n';
        }
        else {
            cout << N << " is NOT perfect.\n";
        }
    }

    return 0;
}