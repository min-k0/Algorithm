#include <iostream>
#include <algorithm>
using namespace std;
int dp[501][501];
int board[501][501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> board[i][j];

    dp[0][0] = board[0][0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= i; j++)
        {
            if(j-1 < 0) dp[i][j] = dp[i - 1][j] + board[i][j];
            else if(i-1 < j) dp[i][j] = dp[i - 1][j - 1] + board[i][j];
            else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + board[i][j];
        }

    sort(dp[n - 1], dp[n - 1] + n);
    cout << dp[n - 1][n - 1];

    return 0;
}
