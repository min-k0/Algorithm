#include <iostream>
#include <utility> //pair
#include <queue>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool visited[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int num = 0;
int temp = 0;
int res = 0;

void bfs(int i, int j) {
    queue<pair<int, int> > Q;
    visited[i][j] = 1;
    temp = 0;
    Q.push({ i,j });
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        temp++;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny] || board[nx][ny] != 1) continue;
            visited[nx][ny] = 1;
            Q.push({ nx,ny });
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] || board[i][j] != 1) continue;
            num++;
            bfs(i, j);
            if (temp > res) res = temp;
        }

    cout << num << "\n" << res;
}
