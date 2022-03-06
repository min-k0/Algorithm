#include <iostream>
#include <vector>
#include <utility> //pair
using namespace std;
#define X first
#define Y second

int n, m;
int board1[10][10];
int board2[10][10];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<pair<int, int>> cctv;

void func(int x, int y, int dir)
{
    dir %= 4;
    while (1)
    {
        x += dx[dir];
        y += dy[dir];

        if (x < 0 || x >= n || y < 0 || y >= m || board2[x][y] == 6) return;
        if (board2[x][y] != 0) continue;
        board2[x][y] = 7;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int res; //답
    cin >> n >> m;
    res = n * m; //최대는 모든 칸이 사각지대인 경우
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board1[i][j];
            if (board1[i][j] != 0 && board1[i][j] != 6)
                cctv.push_back({ i,j });
        }
  
    //1 << (2 * cctv.size() <=> 4^cctv.size()
    for (int tmp = 0; tmp < 1 << (2 * cctv.size()); tmp++) 
    {
        for (int i = 0; i < n; i++) // 각 조합을 확인할 때마다 board2 초기화
            for (int j = 0; j < m; j++)
                board2[i][j] = board1[i][j];

        int brute = tmp;
        for (int i = 0; i < cctv.size(); i++)
        {
            int x = cctv[i].X;
            int y = cctv[i].Y;
            int dir = brute % 4;
            brute /= 4;

            if (board1[x][y] == 1)
            {
                func(x, y, dir);
            }
            else if (board1[x][y] == 2)
            {
                func(x, y, dir);
                func(x, y, dir + 2);

            }
            else if (board1[x][y] == 3)
            {
                func(x, y, dir);
                func(x, y, dir + 1);
            }
            else if (board1[x][y] == 4)
            {
                func(x, y, dir);
                func(x, y, dir + 1);
                func(x, y, dir + 2);
            }
            else if (board1[x][y] == 5)
            {
                func(x, y, dir);
                func(x, y, dir + 1);
                func(x, y, dir + 2);
                func(x, y, dir + 3);
            }
        }
        int space = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board2[i][j] == 0) space++;

        if (res > space) res = space;
    }

    cout << res;
    return 0;
}
