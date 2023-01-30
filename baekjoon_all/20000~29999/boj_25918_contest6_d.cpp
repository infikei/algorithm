#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, cnt;
string S;
stack<char> stck;

int main() {
    fastio;

    cin >> N >> S;

    for (auto a : S) {
        if (stck.empty() || stck.top() == a) {
            stck.push(a);
            cnt = max(cnt, (int)stck.size());
        }
        else {
            stck.pop();
        }
    }

    if (stck.empty()) {
        cout << cnt << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}