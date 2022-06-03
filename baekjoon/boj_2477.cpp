#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int K, key;
    int arr[6][2];

    cin >> K;
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = 0; i < 6; i++)
    {
        if (arr[i][0] == arr[(i + 2) % 6][0] && arr[(i + 1) % 6][0] == arr[(i + 3) % 6][0])
            key = i;
    }

    int area = arr[(key + 4) % 6][1] * arr[(key + 5) % 6][1];
    area -= arr[(key + 1) % 6][1] * arr[(key + 2) % 6][1];

    cout << (area * K) << "\n";

    return 0;
}