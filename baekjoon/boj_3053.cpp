#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double r;
    cin >> r;

    cout << fixed;
    cout.precision(6);

    cout << pow(r, 2) * M_PI << "\n";
    cout << pow(r, 2) * 2 << "\n";

    return 0;
}