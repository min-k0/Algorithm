#include <iostream>
using namespace std;
int isused1[40];
int isused2[40]; // x+y
int isused3[40]; // x-y + n-1

int n, res;

void func(int cur) 
{
	if (cur == n)
	{
		res++;
		return;
	}

	for (int i = 0; i < n; i++) //cur행 i열
	{
		if (isused1[i] || isused2[cur + i] || isused3[cur - i + n - 1])
			continue;
		isused1[i] = isused2[cur + i] = isused3[cur - i + n - 1] = 1;
		func(cur + 1);
		isused1[i] = isused2[cur + i] = isused3[cur - i + n - 1] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0);

	cout << res;

	return 0;
}
