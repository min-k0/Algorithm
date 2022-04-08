#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second

string board[1001]; //1:벽, 0:이동가능한 곳
int visited[1001][1001][2]; //1:방문O, 0:방문X
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs()
{
    queue< pair<pair<int, int>, int> > q;
    visited[0][0][0] = 1;
    q.push(make_pair(make_pair(0, 0), 0));

    while (!q.empty())
    {
        pair<pair<int, int>, int> cur = q.front(); q.pop();

        //(N, M)에 도착한 경우
        if (cur.X.X == n - 1 && cur.X.Y == m - 1)
            return visited[cur.X.X][cur.X.Y][cur.Y];

        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X.X + dx[dir];
            int ny = cur.X.Y + dy[dir];
            int wall = cur.Y;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            // 벽이고, 이전에 부순적이 없는 경우
            if (board[nx][ny] == '1' && wall == 0) 
            {
                visited[nx][ny][wall + 1] = visited[cur.X.X][cur.X.Y][wall] + 1;
                q.push(make_pair(make_pair(nx, ny), wall + 1));
            }

            // 길이고, 이전에 방문한 적 없는 경우
            if (board[nx][ny] == '0' && visited[nx][ny][wall] == 0)
            {
                visited[nx][ny][wall] = visited[cur.X.X][cur.X.Y][wall] + 1;
                q.push(make_pair(make_pair(nx, ny), wall));
            }
        }
    }

    return -1;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> board[i];

    cout << bfs();

    return 0;
}
