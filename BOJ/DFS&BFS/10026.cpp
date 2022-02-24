#include <iostream>
#include <utility> //pair
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

char board[102][102];
int visited[102][102];
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
            if (visited[nx][ny] == 1 || board[nx][ny] != board[cur.X][cur.Y]) continue;
            visited[nx][ny] = 1;
            Q.push({ nx, ny });
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num1 = 0, num2 = 0;
    cin >> n;
    m = n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    //적록색약 아닌 사람
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 1) continue;
            num1++;
            bfs(i, j);
        }
    cout << num1 << " ";

    //적록색약인 사람
    for (int i = 0; i < n; i++)
        fill(visited[i], visited[i] + n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'G')
                board[i][j] = 'R';
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 1) continue;
            num2++;
            bfs(i, j);
        }
    cout << num2 << "\n";

    return 0;
}
