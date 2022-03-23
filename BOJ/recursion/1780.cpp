#include <iostream>
using namespace std;
int board[2200][2200]; //3^7 = 2187
int n;
int res[3] = {0}; //[0]:-1, [1]:0, [2]:1

// 시작점이 (s,e)이고 크기가 kxk인 종이의 값 확인하는 함수
int check(int k, int s, int e) 
{
    int num = board[s][e];
    for (int i = s; i < s + k; i++)
    {
        for (int j = e; j < e + k; j++)
            if (num != board[i][j])
                return 1; // 다른 수가 하나라도 있을 때
    }
    return 0;
}

void func(int k, int s, int e)
{
    bool isFull = true;
    int num = board[s][e];

    if (check(k, s, e) == 0)
    {
        if (num == -1) res[0]++;
        else if (num == 0) res[1]++;
        else if (num == 1) res[2]++;
    }
    else 
    {
        for (int m = 0; m < 3; m++)
            for (int n = 0; n < 3; n++)
            {
                func(k / 3, s + (k / 3) * m, e + (k / 3) * n);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    func(n, 0, 0);  

    for (int i = 0; i < 3; i++)
        cout << res[i] << "\n";

    return 0;
}
