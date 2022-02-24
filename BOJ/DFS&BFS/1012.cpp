#include <iostream>
#include <utility> //pair
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int board[52][52];
int visited[52][52];
int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;

queue<pair<int, int>> Q;

void bfs(int i, int j) {
    visited[i][j] = 1;
    Q.push({ i, j });

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny] == 1 || board[nx][ny] != 1) continue;
            visited[nx][ny] = 1;
            Q.push({ nx, ny });
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; //test case
    while (t--)
    {
        int k, num = 0;
        cin >> m >> n >> k; //**
        for (int i = 0; i < n; i++)
        {
            fill(board[i], board[i] + m, 0);
            fill(visited[i], visited[i] + m, 0);
        }

        while (k--)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1; //**
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] || board[i][j] != 1) continue;
                num++;
                bfs(i, j);
            }
        cout << num << "\n";
    }
    
    return 0;
}
