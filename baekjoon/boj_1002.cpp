#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    int x1, y1, r1, x2, y2, r2;
    double d;

    for (int t = 0; t < T; t++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

        if (x1 == x2 && y1 == y2 && r1 == r2)
        {
            cout << "-1\n";
        }
        else
        {
            int rrr = abs(r1 - r2);
            int rr = r1 + r2;
            if (d < rrr || d > rr)
                cout << "0\n";
            else if (d == rrr || d == rr)
                cout << "1\n";
            else
                cout << "2\n";
        }
    }

    return 0;
}