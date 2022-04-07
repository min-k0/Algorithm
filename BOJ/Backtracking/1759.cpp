#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

char board[16];
char arr[16];
int isused[16]; //0: 사용X, 1: 사용O
int l, c;
vector<char> v;

bool check()
{
    int numC = 0, numV = 0; //numC: 자음 개수, numV: 모음 개수
    for (int i = 0; i < l; i++)
    {
        if (find(v.begin(), v.end(), arr[i]) != v.end())
            numV++;
        else
            numC++;
    }

    if (numV >= 1 && numC >= 2)
        return true;
    else return false;
}

void func(int k, int prev) //k개 문자를 고름
{
    if (k == l && check())
    {
        for (int i = 0; i < l; i++)
            cout << arr[i];
        cout << "\n";
    }

    for (int i = 0; i < c; i++)
    {
        if (!isused[i] && i > prev)
        {
            arr[k] = board[i]; // k번째 문자를 정함
            isused[i] = 1;
            func(k + 1, i);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;
    for (int i = 0; i < c; i++)
        cin >> board[i];
    sort(board, board + c);
    v = { 'a' , 'e' , 'i' , 'o' , 'u' };

    func(0, -1);

    return 0;
}
