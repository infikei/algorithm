#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, K, A[500001], tmp[500001];
int cnt, ans = -1;

void merge(int s, int mid, int e) {
    int i = s, j = mid + 1;
    int t = 1;
    while (i <= mid && j <= e) {
        if (A[i] < A[j]) {
            tmp[t] = A[i];
            i++;
            t++;
        }
        else {
            tmp[t] = A[j];
            j++;
            t++;
        }
    }
    while (i <= mid) {
        tmp[t] = A[i];
        i++;
        t++;
    }
    while (j <= e) {
        tmp[t] = A[j];
        j++;
        t++;
    }

    i = s, t = 1;
    while (i <= e) {
        cnt++;
        if (cnt == K) {
            ans = tmp[t];
        }

        A[i] = tmp[t];
        i++;
        t++;
    }
}

void merge_sort(int s, int e) {
    if (s < e) {
        int mid = (s + e) / 2;

        merge_sort(s, mid);
        merge_sort(mid + 1, e);
        merge(s, mid, e);
    }
}

int main() {
    fastio;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    merge_sort(1, N);

    cout << ans << '\n';

    return 0;
}