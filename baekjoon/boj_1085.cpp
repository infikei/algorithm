#include <iostream>
using namespace std;

int main()
{
    int x, y, w, h, ans;
    cin >> x >> y >> w >> h;

    ans = min(min(x, y), min(w - x, h - y));
    cout << ans;

    return 0;
}