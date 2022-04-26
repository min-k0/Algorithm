#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, h, res = 4;
int board[32][12];

bool testGame()
{
    for (int i = 1; i < n; i++)
    {
        int moveI = i;
        for (int j = 1; j <= h; j++)
        {
            if (board[j][moveI] == 1) moveI++;
            else if (board[j][moveI - 1] == 1) moveI--;
        }
        if (moveI != i)
            return false;
    }
    return true;
}

void dfs(int idx, int cnt)
{
    if (cnt > 3) return;

    if (testGame() == true)
    {
        res = min(res, cnt);
        return;
    }

    for (int i = idx; i < n; i++) //*idx부터 시작, i가 n일 때는 오른쪽으로 이동 안되니까 확인X
    {
        for (int j = 1; j <= h; j++)
        {
            if (board[j][i - 1] || board[j][i + 1] || board[j][i]) continue;
            board[j][i] = 1;
            dfs(i, cnt + 1);
            board[j][i] = 0;
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        board[a][b] = 1;
    }
    
    dfs(1, 0);
    if (res == 4) res = -1;
    cout << res << "\n";

    return 0;
}
