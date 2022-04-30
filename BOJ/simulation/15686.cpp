#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second

int n, m, ans = 99999; //ans의 max값 주의!
int board[51][51];
int dist[51][51];
vector<pair<int, int>> store;
bool selectStore[14];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

queue<pair<int, int>> q;

void bfs()
{
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + n, 101);

    for (int i = 0; i < store.size(); i++)
    {
        if (selectStore[i] == true)
        {
            int x = store[i].first;
            int y = store[i].second;
            dist[x][y] = 0;
            q.push({ x,y });
        }
    }

    while (!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        //cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            int temp = dist[cur.X][cur.Y] + 1;
            if (dist[nx][ny] > temp)
                dist[nx][ny] = temp;
            else continue;
            q.push({ nx, ny });
        }
    }
}


int count()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
                sum += dist[i][j];
        }
    return sum;
}

void dfs(int idx, int cnt)
{
    if (cnt > 0 && cnt <= m)
    {
        bfs();
        ans = min(ans, count());
    }

    for (int i = idx; i < store.size(); i++)
    {
        if (selectStore[i] == true) continue;

        selectStore[i] = true;
        dfs(i + 1, cnt + 1);
        selectStore[i] = false;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
            {
                store.push_back({ i, j });
            }
        }

    dfs(0, 0);

    cout << ans << "\n";

    return 0;
}
