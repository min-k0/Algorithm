#include <iostream>
using namespace std;
int num[22];
int n, s, res;

void func(int cur, int sum) 
{
	if (cur == n) //모든 원소에 대해 선택 여부를 결정했다면
	{
		if (sum == s) //합이 s가 되는 경우만 count함
		{
			res++;
		}
		return;
	}
	func(cur + 1, sum); // num[cur]를 선택 X
	func(cur + 1, sum + num[cur]); //// num[cur]를 선택 O
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	func(0, 0);
	if (s == 0) //합이 0일때
		res--; //공집합인 경우는 빼줘야함

	cout << res;

	return 0;
}
