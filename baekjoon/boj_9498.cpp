#include <iostream>
using namespace std;

int main()
{
    int score;

    cin >> score;
    cout << (score >= 90 ? 'A' : (score >= 80 ? 'B' : (score >= 70 ? 'C' : (score >= 60 ? 'D' : 'F')))) << endl;

    return 0;
}