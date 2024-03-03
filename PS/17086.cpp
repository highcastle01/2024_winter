#include<bits/stdc++.h>

using namespace std;

int board[51][51];
int n, m;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int BFS(int x, int y)
{
	bool vis[51][51] = {false, };
	queue<tuple<int, int, int>> q;
	vis[x][y] = true;
	q.push({x, y, 0});

	while(!q.empty())
	{
		int cx = get<0>(q.front());
		int cy = get<1>(q.front()); 
		int dist = get<2>(q.front()); q.pop();

		if(board[cx][cy])
		{
			return dist;
		}

		for(int dir = 0; dir < 8; dir++)
		{
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if(vis[nx][ny] || nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}

			vis[nx][ny] = true;
			q.push({nx, ny, dist + 1});
		}
	}
}

int main(void)
{
	cin >> n >> m;
	int maxs = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(!board[i][j])
			{
				maxs = max(maxs, BFS(i, j));
			}
		}
	}

	cout << maxs;

	return 0;
}