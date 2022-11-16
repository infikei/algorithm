#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N;
char tier[5] = {'D', 'P', 'G', 'S', 'B'};
vector<int> vec;

int main() {
    fastio;

    cin >> N;
    for (int n = 0; n < N; n++) {
        string difficulty;
        cin >> difficulty;

        int k = stoi(difficulty.substr(1, (int)difficulty.length() - 1));
        for (int i = 0; i < 5; i++) {
            if (difficulty[0] == tier[i]) {
                k += i * 100000;
            }
        }
        vec.push_back(k);
    }

    vector<int> vec_copy = vec;
    sort(vec_copy.begin(), vec_copy.end(), greater<int>());
    vector<int> vec_idx;
    bool check = true;

    for (int i = 0; i < (int)vec.size(); i++) {
        if (vec[i] != vec_copy[i]) {
            vec_idx.push_back(i);
            check = false;
        }
    }

    if (check) {
        cout << "OK\n";
    }
    else {
        cout << "KO\n";
        for (auto a : vec_idx) {
            cout << tier[vec_copy[a] / 100000];
            cout << vec_copy[a] % 100000 << ' ';
        }
        cout << '\n';
    }

    return 0;
}