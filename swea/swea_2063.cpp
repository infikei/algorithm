// Solve 2024-01-01

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    int n;
    cin >> n;

    vector<int> scores(n);

    for (int &score : scores) {
        cin >> score;
    }

    sort(scores.begin(), scores.end());

    cout << scores[n / 2] << '\n';

    return 0;
}
