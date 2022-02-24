#include <iostream>
#include <tuple> //tuple
#include <queue>
#include <algorithm>
using namespace std;
#define X get<0>
#define Y get<1>
#define Z get<2>

int board[102][102][102];
int dist[102][102][102];
int dx[4] = { 1, 0 ,-1, 0};
int dy[4] = { 0, 1, 0, -1};
int dz[2] = { 1, -1 };
int n, m, h;

queue<tuple<int, int, int>> Q;

void bfs() {

    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = X(cur) + dx[dir];
            int ny = Y(cur) + dy[dir];
            int nz = Z(cur) + 0;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (dist[nx][ny][nz] >= 0) continue;
            dist[nx][ny][nz] = dist[X(cur)][Y(cur)][Z(cur)] + 1;
            Q.push({ nx, ny, nz });
        }
        for (int dir = 0; dir < 2; dir++)
        {
            int nx = X(cur);
            int ny = Y(cur);
            int nz = Z(cur) + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (dist[nx][ny][nz] >= 0) continue;
            dist[nx][ny][nz] = dist[X(cur)][Y(cur)][Z(cur)] + 1;
            Q.push({ nx, ny, nz });
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n >> h;
    
    for (int z = 0; z < h; z++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j][z];
                if (board[i][j][z] == 0)
                    dist[i][j][z] = -1;
                if (board[i][j][z] == 1)
                    Q.push({ i, j, z });
            }
    
    bfs();
            
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int z = 0; z < h; z++)
            {
                if (dist[i][j][z] == -1)
                {
                    cout << "-1";
                    return 0;
                }
                if (res < dist[i][j][z]) res = dist[i][j][z];
            }
            
        }
    }
    if (res == 0)
        cout << "0";
    else
        cout << res;

    return 0;
}
