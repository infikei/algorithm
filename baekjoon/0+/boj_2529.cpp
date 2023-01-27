#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int k;
vector<char> ineq;
vector<bool> visited;
vector<int> max_ans, min_ans;

bool cmp_ineq(int a, int b, char c) {
    if (c == '<') return a < b;
    else return a > b;
}

bool find_max_ans(int depth = 0) {
    if (depth == k + 1) return true;

    for (int i = 9; i >= 0; i--) {
        if (visited[i]) continue;
        if (depth > 0 && !cmp_ineq(max_ans.back(), i, ineq[depth - 1])) continue;

        visited[i] = true;
        max_ans.push_back(i);
        if (find_max_ans(depth + 1)) return true;
        max_ans.pop_back();
        visited[i] = false;
    }
    return false;
}

bool find_min_ans(int depth = 0) {
    if (depth == k + 1) return true;

    for (int i = 0; i < 10; i++) {
        if (visited[i]) continue;
        if (depth > 0 && !cmp_ineq(min_ans.back(), i, ineq[depth - 1])) continue;

        visited[i] = true;
        min_ans.push_back(i);
        if (find_min_ans(depth + 1)) return true;
        min_ans.pop_back();
        visited[i] = false;
    }
    return false;
}

int main() {
    fastio;

    cin >> k;
    ineq.assign(k, '>');
    for (int i = 0; i < k; i++) {
        cin >> ineq[i];
    }

    visited.assign(10, false);
    find_max_ans();
    visited.assign(10, false);
    find_min_ans();

    for (auto a : max_ans) cout << a;
    cout << '\n';
    for (auto a : min_ans) cout << a;
    cout << '\n';

    return 0;
}