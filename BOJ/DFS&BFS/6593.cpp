#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define X get<0>
#define Y get<1>
#define Z get<2>

using namespace std;
char board[32][32][32];
int dist[32][32][32];
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,-1,0,1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<tuple<int, int, int>> Q;
int l, r, c;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        int res = 0; //1:esacped, 0:trapped
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) break;

        for (int k = 0; k < l; k++)
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c;j++)
                {
                    cin >> board[i][j][k];
                    dist[i][j][k] = -1;
                    if (board[i][j][k] == 'S')
                    {
                        Q.push({ i,j,k });
                        dist[i][j][k] = 0;
                    }
                }

        while (!Q.empty())
        {
            tuple<int, int, int> cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 6; dir++)
            {
                int nx = X(cur) + dx[dir];
                int ny = Y(cur) + dy[dir];
                int nz = Z(cur) + dz[dir];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
                if (board[nx][ny][nz] == '#' || dist[nx][ny][nz] != -1) continue;

                dist[nx][ny][nz] = dist[X(cur)][Y(cur)][Z(cur)] + 1;

                if (board[nx][ny][nz] == 'E')
                {
                    cout << "Escaped in " << dist[nx][ny][nz] << " minute(s).\n";
                    res = 1;
                    break;
                }
                Q.push({ nx,ny,nz });
            }
        }
        if(res == 0)
            cout << "Trapped!\n";

    }
    
    
    return 0;
}
