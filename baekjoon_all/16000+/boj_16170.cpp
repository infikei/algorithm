// Solve 2025-07-20

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    cout << t->tm_year + 1900 << '\n';
    cout << t->tm_mon + 1 << '\n';
    cout << t->tm_mday << '\n';
    return 0;
}
