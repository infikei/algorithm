// Solve 2022-07-27
// Update 2023-03-02

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

int heap[100010];
int heap_end;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(int x) {
    heap_end++;
    heap[heap_end - 1] = x;

    int child = heap_end - 1;
    int parent = child / 2;
    
    while (child > 1 && heap[parent] > heap[child]) {
        swap(&heap[parent], &heap[child]);
        child = parent;
        parent = child / 2;
    }
}

int pop() {
    if (heap_end == 1) {
        return 0;
    }

    int res = heap[1];
    swap(&heap[1], &heap[heap_end - 1]);
    heap_end--;

    int parent = 1;
    int child = parent * 2;
    
    while (true) {
        if (child + 1 < heap_end && heap[child] > heap[child + 1]) {
            child++;
        }
        if (child >= heap_end || heap[child] >= heap[parent]) {
            break;
        }
        swap(&heap[parent], &heap[child]);
        parent = child;
        child = parent * 2;
    }

    return res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    heap_end = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            cout << pop() << '\n';
        }
        else {
            push(x);
        }
    }

    return 0;
}