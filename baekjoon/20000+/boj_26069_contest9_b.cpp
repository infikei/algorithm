#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N;
unordered_map<string, int> rainbow_dance;

int main() {
    fastio;

    cin >> N;
    rainbow_dance["ChongChong"] = 1;

    string person0, person1;
    for (int n = 0; n < N; n++) {
        cin >> person0 >> person1;
        if (rainbow_dance.find(person0) == rainbow_dance.end()) {
            if (rainbow_dance.find(person1) != rainbow_dance.end()) {
                rainbow_dance[person0] = 1;
            }
        }
        else {
            if (rainbow_dance.find(person1) == rainbow_dance.end()) {
                rainbow_dance[person1] = 1;
            }
        }
    }

    cout << rainbow_dance.size() << '\n';

    return 0;
}