// Solve 2023-03-31

#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    stringstream ss(my_string);
    string s;

    ss >> s;
    int answer = stoi(s);

    while (ss >> s) {
        if (s == "+") {
            ss >> s;
            answer += stoi(s);
        }
        else {
            ss >> s;
            answer -= stoi(s);
        }
    }

    return answer;
}
