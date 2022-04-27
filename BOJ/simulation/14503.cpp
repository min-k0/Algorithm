#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int board[51][51];
int visited[51][51];

int dx[4] = { -1,0,1,0 }; //0:북,1:동,2:남,3:서
int dy[4] = { 0,1,0,-1 };

bool isInside(int nx, int ny)
{
    if (nx <= 0 || nx >= n-1 || ny <= 0 || ny >= m-1)
        return false;
    else
        return true;
}

void clean(int x, int y, int dir, int cnt)
{
    //cout << "(" << x << ", " << y << ")->";
    visited[x][y] = 1;

    if (cnt == 4)
    {
        x = x + dx[(dir + 2) % 4];
        y = y + dy[(dir + 2) % 4];
        cnt = 0;
        if (board[x][y] == 1)
            return;
    }

    dir = (dir + 3) % 4;
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (isInside(nx, ny) && board[nx][ny] != 1 && visited[nx][ny]==0)
        clean(nx, ny, dir, 0);
    else
        clean(x, y, dir, cnt+1);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, d, res = 0;
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    clean(r, c, d, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (visited[i][j] == 1 && board[i][j] == 0)
                res++;
    cout << res;

    return 0;
}
