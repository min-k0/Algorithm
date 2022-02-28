#include <iostream>
#include <utility> //pair
#include <queue>
#include <algorithm> //fill
using namespace std;
#define X first
#define Y second

char board[1002][1002];
int dist_j[1002][1002];
int dist_fire[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    queue<pair<int, int> > Q_fire;
    queue<pair<int, int> > Q_j;

    while (t--)
    {
        bool flag = false;
        int n, m;
        cin >> m >> n;

        for (int i = 0; i < n; i++)
        {
            fill(dist_fire[i], dist_fire[i] + m, -1);
            fill(dist_j[i], dist_j[i] + m, -1);
        }


        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == '*')
                {
                    dist_fire[i][j] = 0;
                    Q_fire.push({ i, j });
                }
                if (board[i][j] == '@')
                {
                    dist_j[i][j] = 0;
                    Q_j.push({ i, j });
                }
            }

        // fire bfs
        while (!Q_fire.empty()) {
            pair<int, int> cur = Q_fire.front(); Q_fire.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (dist_fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                dist_fire[nx][ny] = dist_fire[cur.X][cur.Y] + 1;
                Q_fire.push({ nx,ny });
            }
        }

        // 상근 bfs
        while (!Q_j.empty() && (!flag)) { //**
            pair<int, int> cur = Q_j.front(); Q_j.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
                {
                    cout << dist_j[cur.X][cur.Y] + 1 << "\n";
                    flag = true;
                    break; //**
                }
                if (dist_j[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                if (dist_fire[nx][ny] != -1 && dist_j[cur.X][cur.Y] + 1 >= dist_fire[nx][ny]) continue;
                dist_j[nx][ny] = dist_j[cur.X][cur.Y] + 1;
                Q_j.push({ nx,ny });
            }
        }
        if(!flag)
            cout << "IMPOSSIBLE\n";

        while (!Q_fire.empty()) //**
            Q_fire.pop();
        while (!Q_j.empty()) //**
            Q_j.pop();
    }


    return 0;
}
