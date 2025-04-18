// Solve 2023-03-21
// Update 2025-04-16

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = new_id;

    // Step 1

    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

    // Step 2

    for (int i = 0; i < answer.length(); i++) {
        if (islower(answer[i]) || isdigit(answer[i]) || answer[i] == '-' || answer[i] == '_' || answer[i] == '.') {
            continue;
        }

        answer.erase(answer.begin() + i);
        i--;
    }

    // Step 3

    for (int i = 1; i < answer.length(); i++) {
        if (answer[i] == '.' && answer[i - 1] == '.') {
            answer.erase(answer.begin() + i);
            i--;
        }
    }

    // Step 4

    while (!answer.empty() && answer[0] == '.') {
        answer.erase(answer.begin());
    }

    while (!answer.empty() && answer.back() == '.') {
        answer.pop_back();
    }

    // Step 5

    if (answer.empty()) {
        answer = "a";
    }

    // Step 6

    if (answer.size() >= 16) {
        answer.erase(answer.begin() + 15, answer.end());
    }

    while (!answer.empty() && answer.back() == '.') {
        answer.pop_back();
    }

    // Step 7

    while (answer.size() <= 2) {
        answer.push_back(answer.back());
    }

    return answer;
}
