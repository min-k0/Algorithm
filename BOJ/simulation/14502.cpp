#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int n, m;
int board[9][9];
int dist[9][9];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> virus;
queue<pair<int, int>> q;

void bfs()
{
	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + m, -1);

	for (int k = 0; k < virus.size(); k++)
	{
		pair<int, int> temp = virus[k];
		dist[temp.X][temp.Y] = 0;
		q.push({ temp.X , temp.Y });
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] == 1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}
}

int countSafeSpace()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] == -1 && board[i][j] == 0)
				cnt++;
		}
	return cnt;
}


int ans = 0;
void buildWall(int cnt)
{
	if (cnt == 3)
	{
		bfs();
		ans = max(ans, countSafeSpace());
		return;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
			{
				board[i][j] = 1;
				buildWall(cnt + 1);
				board[i][j] = 0;
			}
		}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
				virus.push_back({ i, j });
		}

	dfs(0);
	cout << ans;
	
	return 0;
}
