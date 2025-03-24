// Solve 2023-08-14

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer = arr;
    int sz = answer.size();

    for (int i = 1 - sz % 2; i < sz; i += 2) {
        answer[i] += n;
    }

    return answer;
}
