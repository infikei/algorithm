#include <iostream>
using namespace std;

int heap[100010];
int heap_end;
int N, x;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

    int result = heap[1];
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

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;
    heap_end = 1;

    for (int i = 0; i < N; i++) {
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