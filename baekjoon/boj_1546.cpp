#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    int n;
    cin >> n;

    int score[n];
    int max = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
        sum += score[i];
        if (score[i] > max)
        {
            max = score[i];
        }
    }

    float ans;
    ans = (sum * 100.0) / (n * max);

    cout << ans << "\n";

    return 0;
}