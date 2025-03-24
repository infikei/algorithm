// Solve 2023-03-28

#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    stringstream ss(s);
    string w;
    vector<int> vec;
    while (ss >> w) {
        if (w == "Z") {
            vec.pop_back();
        }
        else {
            vec.push_back(stoi(w));
        }
    }

    int answer = 0;
    for (int i : vec) {
        answer += i;
    }

    return answer;
}
