// Solve 2022-07-27
// Update 2024-02-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int heap[100001];
int heap_end = 1;

void push(int x) {
    int cur_node = heap_end++;
    int cur_parent = cur_node / 2;

    while (cur_parent >= 1 && heap[cur_parent] > x) {
        heap[cur_node] = heap[cur_parent];
        cur_node = cur_parent;
        cur_parent /= 2;
    }

    heap[cur_node] = x;
}

int pop() {
    if (heap_end == 1) return 0;

    int value_return = heap[1];
    int value_move = heap[--heap_end];
    int cur_node = 1;
    int cur_child = 2;

    while (cur_child < heap_end) {
        if (cur_child + 1 < heap_end && heap[cur_child] > heap[cur_child + 1]) {
            cur_child++;
        }

        if (value_move <= heap[cur_child]) break;

        heap[cur_node] = heap[cur_child];
        cur_node = cur_child;
        cur_child *= 2;
    }

    heap[cur_node] = value_move;
    return value_return;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    while (n-- > 0) {
        int x;
        cin >> x;

        if (x == 0) cout << pop() << '\n';
        else push(x);
    }

    return 0;
}
