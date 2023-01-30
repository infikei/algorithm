// 6549번과 동일한 문제
// 스택을 이용한 풀이법

#include <iostream>
#include <stack>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, ans, histogram[100002];
stack<int> stck;

int main() {
    fastio;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> histogram[i];
    }

    stck.push(0);
    for (int i = 1; i <= N + 1; i++) {
        while (!stck.empty() && histogram[stck.top()] > histogram[i]) {
            int k = stck.top();
            stck.pop();
            ans = max(ans, (i - 1 - stck.top()) * histogram[k]);
        }

        stck.push(i);
    }

    cout << ans << '\n';

    return 0;
}