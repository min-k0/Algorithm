#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int board[101][101];
int visited[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> Q;
int n, height = 0;

void bfs()
{
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4;dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] <= height || visited[nx][ny] == 1) continue;
            visited[nx][ny] = 1;
            Q.push({ nx, ny });
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int res = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (height < board[i][j])
                height = board[i][j];
        }

    while (height >= 0)
    {
        int num = 0;
        for (int i = 0; i < n; i++)
            fill(visited[i], visited[i] + n, 0);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] > height && visited[i][j] == 0)
                {
                    visited[i][j] = 1;
                    Q.push({ i, j });
                    bfs();
                    num++;
                }
            }

        if (res < num) res = num;
        height--;
    }

    cout << res;
    return 0;
}
