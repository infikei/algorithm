// Solve 2023-03-21

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    long long k = 0;
    for (int i = 0; i < n; i++) {
        k += x;
        answer.push_back(k);
    }

    return answer;
}
