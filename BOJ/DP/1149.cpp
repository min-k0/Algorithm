#include <iostream>
#include <algorithm> //min
using namespace std;

int dp[1001][3];
int S[1001][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			cin >> S[i][j];

	dp[1][0] = S[1][0];
	dp[1][1] = S[1][1];
	dp[1][2] = S[1][2];
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + S[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + S[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + S[i][2];
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));

	return 0;
}
