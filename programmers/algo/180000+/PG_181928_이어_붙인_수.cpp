// Solve 2025-10-19

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> num_list) {
    string even = "";
    string odd = "";

    for (int num : num_list) {
        if (num % 2 == 0) {
            even += to_string(num);
        }
        else {
            odd += to_string(num);
        }
    }

    return stoi(even) + stoi(odd);
}
