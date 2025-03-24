// Solve 2023-03-31

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    unordered_set<string> us;
    for (auto w : s1) {
        us.insert(w);
    }

    int answer = 0;
    for (auto w : s2) {
        if (us.find(w) != us.end()) {
            answer++;
        }
    }

    return answer;
}
