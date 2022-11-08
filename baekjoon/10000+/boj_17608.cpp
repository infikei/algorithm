#include <iostream>
#include <stack>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N;
stack<int> stck;

int main() {
    fastio;

    cin >> N;

    for (int n = 0; n < N; n++) {
        int x;
        cin >> x;

        while (!stck.empty() && stck.top() <= x) {
            stck.pop();
        }
        stck.push(x);
    }

    cout << (int)stck.size() << '\n';

    return 0;
}