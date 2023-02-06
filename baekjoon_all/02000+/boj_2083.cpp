#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    while (true) {
        string name;
        int age, kg;
        cin >> name >> age >> kg;
        if (name == "#" && age == 0 && kg == 0) {
            break;
        }

        if (age > 17 || kg >= 80) {
            cout << name << " Senior\n";
        }
        else {
            cout << name << " Junior\n";
        }
    }

    return 0;
}