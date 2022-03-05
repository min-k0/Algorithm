#include <iostream>
#include <algorithm> //min
using namespace std;

int dp[1000001];
int pre[1000001]; //복원용 테이블

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	dp[1] = 0;
	pre[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2])
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
			pre[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3])
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
			pre[i] = i / 3;
		}
	}
	cout << dp[n] << "\n";

	int i = n;
	while (i > 0)
	{
		cout << i << " ";
		i = pre[i];
	}

	return 0;
}
