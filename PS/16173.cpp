#include<bits/stdc++.h>

using namespace std;

int board[3][3];
bool vis[3][3];

int n;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	vis[x][y] = true;
	q.push({x, y});

	while(!q.empty())
	{
		auto cur = q.front(); q.pop();
		for(int dir = 0; dir < 2; dir++)
		{
			int nx = cur.first + dx[dir] * board[cur.first][cur.second];
			int ny = cur.second + dy[dir] * board[cur.first][cur.second];

			if(nx < 0 || nx >= n || ny < 0 || ny >= n)
			{
				continue;
			}

			if(!vis[nx][ny])
			{
				q.push({nx, ny});
				vis[nx][ny] = true;
			}
		}
	}
}

int main(void)
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	BFS(0, 0);

	if(vis[n-1][n-1])
	{
		cout << "HaruHaru";
	}
	else
	{
		cout << "Hing";
	}
	return 0;
}