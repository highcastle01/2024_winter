#include<bits/stdc++.h>

using namespace std;

#define H first
#define W second

int board[51][51];
bool vis[51][51];

int dh[8] = {-1, -1, -1, 0, 0, 1 , 1, 1};
int dw[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void BFS(int x, int y, int w, int h)
{
	queue<pair<int, int>> q;
	vis[x][y] = true;
	q.push({x, y});

	while(!q.empty())
	{
		auto cur = q.front(); q.pop();

		for(int dir = 0; dir < 8; dir++)
		{
			int nh = cur.H + dh[dir];
			int nw = cur.W + dw[dir];

			if(nh < 0 || nh >= h || nw < 0 || nw >= w)
			{
				continue;
			}

			if(!vis[nh][nw] && board[nh][nw])
			{
				vis[nh][nw] = true;
				q.push({nh, nw});
			}
		}
	}
}

int main(void)
{
	while(1)
	{
		memset(vis, 0, sizeof(vis));
		memset(board, 0, sizeof(board));
		int w, h; cin >> w >> h;
		int cnt = 0;
		if(w == 0 && h == 0)
		{
			break;
		}

		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				cin >> board[i][j];
			}
		}

		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				if(!vis[i][j] && board[i][j])
				{
					BFS(i, j, w, h);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";

	}

	return 0;
}