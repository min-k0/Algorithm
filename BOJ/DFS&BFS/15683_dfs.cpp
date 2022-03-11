#include <iostream>
#include <vector>
#include <utility> //pair
using namespace std;
#define X first
#define Y second

int n, m;
int board1[10][10]; // 입력받은 각 칸의 정보 저장할 배열
int board2[10][10]; // 감시 가능한 칸을 7로 표시할 배열 
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<pair<int, int>> cctv;
int res;

// dir 방향을 바라봤을 때 감시 가능한 칸을 7로 바꿔주는 함수
void marker(int x, int y, int dir)
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

// prev를 cur에 복사하는 함수
void copyBoard(int cur[10][10], int prev[10][10])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cur[i][j] = prev[i][j];
}

void dfs(int cctvIndex) {
	//=====================================================
	// base condition
	//=====================================================
	if (cctvIndex == cctv.size())
	{
		// 사각지대가 아닌 것을 세는 부분
		int space = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (board2[i][j] == 0) space++;

		// 현재 count가 최소인지 확인
		if (res > space) res = space;

		return;
	}
	//=====================================================

	int backup[10][10];
	int x = cctv[cctvIndex].first;
	int y = cctv[cctvIndex].second;
  
  // 바꿀 수 있는 방향 종류는 최대 4가지(구현의 편의상 4로 통일)
	for (int dir = 0; dir < 4; dir++) { 

		copyBoard(backup, board2); //board2를 backup에 복사해둠

		//=====================================================
		// cctv 종류에 따라 marking
		//=====================================================
		if (board1[x][y] == 1)
		{
			marker(x, y, dir); // 기본방향
		}
		else if (board1[x][y] == 2)
		{
			marker(x, y, dir); // 기본방향
			marker(x, y, dir + 2); // 기본방향 + 180도

		}
		else if (board1[x][y] == 3)
		{
			marker(x, y, dir); // 기본방향
			marker(x, y, dir + 1); // 기본방향 + 90도
		}
		else if (board1[x][y] == 4)
		{
			marker(x, y, dir); // 기본방향
			marker(x, y, dir + 1); // 기본방향 + 90도
			marker(x, y, dir + 2); // 기본방향 + 180도
		}
		else if (board1[x][y] == 5)
		{
			marker(x, y, dir); // 기본방향
			marker(x, y, dir + 1); // 기본방향 + 90도
			marker(x, y, dir + 2); // 기본방향 + 180도
			marker(x, y, dir + 3); // 기본방향 + 270도
		}
		//=====================================================

		dfs(cctvIndex + 1); // 다음 cctv로 넘어감
		copyBoard(board2, backup); //return된 다음에는 복사해둔 backup을 가져와서 그 상태부터 시작
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	//====================================================
	// 입력된 data를 받아서 배열에 초기화 해주는 부분
	//====================================================
	cin >> n >> m;
	res = n * m; //최대는 모든 칸이 사각지대인 경우
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> board1[i][j];
			board2[i][j] = board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6)
				cctv.push_back({ i,j });
		}
	//=====================================================

	dfs(0);

	// 최종 답(res) 출력
	cout << res;
	return 0;
}
