#include <iostream>
#include <algorithm>
using namespace std;

int board[21][21];
int dice[7] = {0}; //1:위,2:북,3:동,4:서,5:남,6:아래
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int nx = x;
    int ny = y;
    for (int i = 0; i < k; i++)
    {
        int command, temp;
        cin >> command;

        nx += dx[command - 1];
        ny += dy[command - 1];

        //cout << "(" << nx << "," << ny << ")";

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        {
            nx -= dx[command - 1];
            ny -= dy[command - 1];
            continue;
        }

        switch (command) 
        {
        case 1:
            temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
            break;
        case 2:
            temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
            break;
        case 3:
            temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
            break;
        case 4:
            temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
            break;
        }

        if (board[nx][ny] == 0)
            board[nx][ny] = dice[6];
        else
        {
            dice[6] = board[nx][ny];
            board[nx][ny] = 0;
        }
        cout << dice[1] << "\n";
    }


    
    return 0;
}
