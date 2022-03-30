#include <iostream>
#include <algorithm>
using namespace std;
long long num[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num, num + n);

    int maxCount = 0, temp = 1;
    long long res;
    for (int idx = 1; idx < n; idx++)
    {
        if (num[idx] == num[idx - 1])
            temp++;
        else
        {
            if (maxCount < temp)
            {
                maxCount = temp;
                res = num[idx-1];
            }
            temp = 1;
        }
    }

    // 마지막 수가 몇 번 등장했는지 따로 확인해줘야함
    if (maxCount < temp) res = num[n - 1];
    cout << res;
}
