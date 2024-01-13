#include<bits/stdc++.h>

using namespace std;

int n, m, k;

int board[1001][1001];
int dist[1001][1001][11];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS()
{
	queue<tuple<int, int, int>> q;

	q.push({0, 0, 0}); //출발점 넣기
	dist[0][0][0] = 1; //출발점 방문 넣기

	while(!q.empty())
	{
		int x, y, w;
		tie(x, y, w) = q.front(); q.pop();

		if(x == n-1 && y == m-1)
		{
			cout << dist[x][y][w];
			return;
		}

		for(int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue; //영역 벗어난 거 제외
			}

			int nw = w; //새로 벽부수는 걸 세기 위해 새로운 변수

			if(board[nx][ny])
			{
				nw++; //방문한 곳에 벽이 있으면 일단 부수는 횟수 추가
			}

			if(nw > k || dist[nx][ny][nw] > 0)
			{
				continue; //벽부수기 횟수제한 넘거나, 이미 다른경로에서 그만큼 벽부수기를 했을 경우(지금 위치가 최단경로가 아닌경우)
			}
			dist[nx][ny][nw] = dist[x][y][w] + 1;
			q.push({nx, ny, nw});
		}
	}
	cout << -1; //결판이 안난 경우
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for(int i = 0; i < n; i++)
	{
		string row; cin >> row;
		for(int j = 0; j < m; j++)
		{
			board[i][j] = row[j] - '0';
		}
	}

	BFS();


	return 0;
}