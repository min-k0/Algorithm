#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[301][301];
int tmpBoard[301][301];
int visited[301][301];
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };


void bfs(int i, int j) {
    queue<pair<int, int> > Q;
    visited[i][j] = 1;
    Q.push({ i,j });
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        //cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny] || board[nx][ny] <= 0) continue;
            visited[nx][ny] = 1;
            Q.push({ nx,ny });
        }
    }
}

int check()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        fill(visited[i], visited[i] + m, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] > 0 && visited[i][j] == 0)
            {
                bfs(i, j);
                cnt++;
            }
        }
    return cnt;
}

int zeroCount(int x, int y)
{
    int tempCnt = 0;
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (board[nx][ny] <= 0) tempCnt++;
    }
    return tempCnt;
}

void melting()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] > 0)
                tmpBoard[i][j] = board[i][j] - zeroCount(i, j);
            if (tmpBoard[i][j] < 0) tmpBoard[i][j] = 0;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = tmpBoard[i][j];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            tmpBoard[i][j] = board[i][j];
        }

    int year = 0;
    while (1)
    {
        if (check() >= 2) break;
        if (check() == 0)
        {
            year = 0;
            break;
        }
        melting();
        year++;
    }

    cout << year;

    return 0;
}
