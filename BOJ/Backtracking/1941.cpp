#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

string board[5];
bool isSelect[25];
vector<int> v;
int sum;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isFour()
{
    int temp = 0;
    for (int i = 0; i < 7;i++)
    {
        int x = v[i] / 5;
        int y = v[i] % 5;
        if (board[x][y] == 'S')
            temp++;
    }
    if (temp >= 4)
        return true;
    else
        return false;
}

int bfs()
{
    queue<pair<int, int> > q;
    int visited[5][5] = {0};
    int numOfS = 1;
    int x = v[0] / 5;
    int y = v[0] % 5;

    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while (!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (visited[nx][ny] == 1 || isSelect[nx * 5 + ny] == false) continue;
            numOfS++;
            visited[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
    return numOfS;
}

bool isNear()
{
    if (bfs() == 7)
        return true;
    else
        return false;
}

void solve(int idx, int cnt)
{
    if (cnt == 7)
    {
        if (isFour() && isNear())
            sum++;

        return;
    }

    for (int i = idx; i < 25; i++)
    {
        if (isSelect[i] == true) continue;

        isSelect[i] = true;
        v.push_back(i);
        solve(i, cnt + 1);
        isSelect[i] = false;
        v.pop_back();
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        cin >> board[i];

    solve(0, 0);
    cout << sum;

    return 0;
}
