#include <iostream>
#include <algorithm>
using namespace std;

int board[501][501];
int visited[501][501];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, res;

void dfs(int i, int j, int depth, int sum)
{
    if (depth > 3)
    {
        res = max(res, sum);
        return;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] == 1) continue;

        visited[nx][ny] = 1;
        dfs(nx, ny, depth + 1, sum + board[nx][ny]);
        visited[nx][ny] = 0;
    }
}

void check(int x, int y)
{
    if(x + 1 < n && y+2 <m) // ㅜ
        res = max(res, board[x][y] + board[x][y+1] + board[x][y+2] + board[x + 1][y + 1]);
    if (x + 1 < n && y + 2 < m) // ㅗ
        res = max(res, board[x][y + 1] + board[x + 1][y] + board[x + 1][y + 1] + board[x + 1][y + 2]);
    if (x + 2 < n && y + 1 < m) // ㅏ
        res = max(res, board[x][y] + board[x + 1][y] + board[x + 2][y] + board[x + 1][y + 1]);
    if (x + 2 < n && y + 1 < m) // ㅓ
        res = max(res, board[x + 1][y] + board[x][y + 1] + board[x + 1][y + 1] + board[x + 2][y + 1]);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 1;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = 0;
            check(i, j);
        }

    cout << res;
    
    return 0;
}
