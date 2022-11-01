// 빠른 선택 (quick select) 알고리즘

#include <iostream>
#include <vector>
using namespace std;

int quick_select(const vector<int>& vt, int k) {
    vector<int> small, same, big;

    int pivot = vt[0];
    int vt_len = vt.size();

    for (int i = 0; i < vt_len; i++) {
        if (vt[i] < pivot) {
            small.push_back(vt[i]);
        }
        else if (vt[i] > pivot) {
            big.push_back(vt[i]);
        }
        else {
            same.push_back(vt[i]);
        }
    }

    if ((int)small.size() >= k) {
        return quick_select(small, k);
    }
    else if ((int)small.size() + (int)same.size() < k) {
        return quick_select(big, k - (int)small.size() - (int)same.size());
    }
    else {
        return pivot;
    }
}