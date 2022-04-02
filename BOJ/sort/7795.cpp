#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int& a, int& b)
{
    return a > b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m;

    cin >> t;
    while (t--)
    {
        int sum = 0;
        cin >> n >> m;
        vector<int> a(n), b(m); //**

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end(), cmp);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (a[i] > b[j])
                {
                    sum += (m - j);
                    break;
                }
            }
        cout << sum << "\n";
    }

    return 0;
}
