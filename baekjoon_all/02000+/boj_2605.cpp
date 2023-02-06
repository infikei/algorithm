#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N;
vector<int> students;

int main() {
    fastio;

    cin >> N;

    for (int n = 1; n <= N; n++) {
        int x;
        cin >> x;
        students.insert(students.begin() + (n - x - 1), n);
    }

    for (auto a : students) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}