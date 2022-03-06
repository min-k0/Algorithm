#include <iostream>
#include <queue>
#include <algorithm> //fill
#include <vector>
using namespace std;
#define X first
#define Y second
int board[101][101];
int visited[101][101]; //0이면 방문X, 1이면 방문O
vector<int> sum;
int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, -1, 0, 1 };
int m, n, k;
int num = 0; // 나누어지는 영역의 개수

queue<pair<int, int>> Q;

void bfs() {
    int temp = 1;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        // cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny] == 1 || board[nx][ny] == 1) continue;
            visited[nx][ny] = 1;
            temp++;
            Q.push({ nx, ny });
        }
    }
    sum.push_back(temp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k; //n: 행의 수, m: 열의 수로 봄

    for (int i = 0; i < k; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++)
            for (int y = y1; y < y2; y++)
                board[x][y] = 1; //1이 벽, 0이 지나갈 수 있는 칸
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            //지나갈 수 있는 칸이고, 아직 방문 안했다면
            if (board[i][j] == 0 && visited[i][j] == 0)
            {
                visited[i][j] = 1;
                Q.push({ i,j });
                bfs();
                num++;
            }
        }

    cout << num << "\n";
    sort(sum.begin(), sum.end());
    for (int u : sum)
        cout << u << " ";

    return 0;
}
