#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int board[101][101]; // 1:사과, 2:뱀
int direction[10001]; //0:그대로, 1:오른쪽, 2:왼쪽

queue<pair<int, int> > snake;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, x, y;
    cin >> n >> k;

    while (k--)
    {
        cin >> x >> y;
        board[x][y] = 1;
    }

    int l;
    cin >> l;
    while (l--)
    {
        int tempX;
        char tempDir;
        cin >> tempX >> tempDir;
        if (tempDir == 'D')
            direction[tempX] = 1;
        else if(tempDir == 'L')
            direction[tempX] = 2;
    }

    int nx = 1, ny = 1, dir = 0, cnt = 0;
    board[nx][ny] = 2;
    snake.push({ nx, ny });
    while (1)
    {
        cnt++;
        nx += dx[dir];
        ny += dy[dir];

        if (nx <= 0 || nx > n || ny <= 0 || ny > n) break;
        if (board[nx][ny] == 2) break;

        if (board[nx][ny] == 0)
        {
            pair<int, int> end = snake.front(); snake.pop();
            board[end.first][end.second] = 0;
        }
        snake.push({ nx, ny });
        board[nx][ny] = 2;

        //cnt초가 끝난 뒤 그 다음 방향 설정
        if (direction[cnt] == 1)
            dir = (dir + 1) % 4;
        else if (direction[cnt] == 2)
            dir = (dir - 1 + 4) % 4;        
    }
    cout << cnt;
    
    return 0;
}
