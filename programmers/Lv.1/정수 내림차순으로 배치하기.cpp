// Solve 2023-03-21

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string s = to_string(n);
    sort(s.begin(), s.end(), greater<int>());
    long long answer = stol(s);

    return answer;
}
