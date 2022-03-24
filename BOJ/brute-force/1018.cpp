#include <iostream>
#include <algorithm>
using namespace std;
char board[51][51];
char start[2] = { 'W', 'B' };
int n, m;

int check(int x, int y)
{
    int res = n*m;
    for (int k = 0; k < 2; k++)
    {
        int temp = 0;
        for (int i = x; i < x + 8; i++)
            for (int j = y; j < y + 8; j++)
            {
                if ((i + j) % 2 == (x + y) % 2)
                {
                    if (start[k] != board[i][j])
                        temp++;
                }
                else {
                    if (start[k] == board[i][j])
                        temp++;
                }
            }
        if (res > temp) res = temp;
    }
    
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int minValue;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    minValue = n * m;
    for (int i = 0; i <= n - 8; i++)
        for (int j = 0; j <= m - 8; j++)
        {
            int tmp = check(i, j);
            if (minValue > tmp)
                minValue = tmp;
        }

    cout << minValue;

    return 0;
}
