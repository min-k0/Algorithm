#include <iostream>
using namespace std;

int dp[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		dp[1] = 1; dp[2] = 2; dp[3] = 4;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << "\n";
	}

	return 0;
}
