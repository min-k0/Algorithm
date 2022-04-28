#include <iostream>
#include <algorithm>
using namespace std;

int wheel[4][9];
int case1[] = { -1,1,-1,1 };
int case2[] = { 1,-1,1,-1 };
int isRotate[4];

void rotation(int state[], int dir)
{
    if (dir == -1) //반시계
    {
        int temp = state[0];
        for (int i = 1; i < 8; i++)
            state[i-1] = state[i];
        state[7] = temp;
    }
    else if (dir == 1) //시계
    {
        int temp = state[7];
        for (int i = 6; i >= 0; i--)
            state[i + 1] = state[i];
        state[0] = temp;
    }
}

void check(int idx)
{
    isRotate[idx] = 1;
    for (int i = idx; i <= 3; i++) // right check
    {
        if (wheel[i][2] != wheel[i + 1][6])
            isRotate[i+1] = 1;
        else break;
    }
    for (int i = idx - 1; i >= 0; i--) // left check
    {
        if (wheel[i][2] != wheel[i + 1][6])
            isRotate[i] = 1;
        else break;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    string temp;
    for (int i = 0; i < 4; i++)
    {
        cin >> temp;
        for (int j = 0; j < 8; j++)
        {
            wheel[i][j] = temp[j] - '0';
        }
    }

    cin >> k;
    while (k--)
    {
        int numOfWheel, dir;
        cin >> numOfWheel >> dir;
        fill(isRotate, isRotate + 4, 0);

        check(numOfWheel-1);

        if (case1[numOfWheel-1] == dir)
        {
            for (int i = 0; i < 4; i++)
            {
                if (isRotate[i] == 1)
                    rotation(wheel[i], case1[i]);
            }
        }
        else 
        {
            for (int i = 0; i < 4; i++)
            {
                if (isRotate[i] == 1)
                    rotation(wheel[i], case2[i]);
            }
        }
    }

    int res = 0;
    if (wheel[0][0] == 1) res++;
    if (wheel[1][0] == 1) res += 2;
    if (wheel[2][0] == 1) res += 4;
    if (wheel[3][0] == 1) res += 8;

    cout << res;

    return 0;
}
