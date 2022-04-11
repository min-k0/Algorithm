#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int board[100001];
int visited[100001];
bool finished[100001];
int sum;

void dfs(int cur)
{
    //cout << cur << "->";
    visited[cur] = 1;
    int next = board[cur];

    if (!visited[next])
        dfs(next);
    else
    {
        if (!finished[next])
        {
            for (int i = next; i != cur; i = board[i])
                sum++;
            sum++;
        }
    }
    finished[cur] = true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        fill(board, board + n+1, 0);
        fill(visited, visited + n + 1, 0);
        fill(finished, finished + n + 1, 0);

        sum = 0;

        for (int i = 1; i <= n; i++)
            cin >> board[i];


        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i);
                //cout << "\n";
            }
        }
        cout << n - sum << "\n";
    }

    return 0;
}
