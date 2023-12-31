#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

bool vis[100];
pair<int, int> CU[100];

// int dx[4] = {-50, 50, 0, 0};
// int dy[4] = {0, 0, -50, 50};

int beer = 20;
int t, n;
int sx, sy, ex, ey;

bool BFS()
{
	queue<pair<int, int>> q;

	q.push({sx, sy});

	while(!q.empty())
	{
		auto cur = q.front(); q.pop();

		if(abs(ex - cur.X) + abs(ey - cur.Y) <= 1000)
		{
			return true;
		}

		for(int dir = 0; dir < n; dir++)
		{
			if(vis[dir])
			{
				continue;
			}
			if(abs(CU[dir].X - cur.X) + abs(CU[dir].Y - cur.Y) <= 1000)
			{
				vis[dir] = true;
				q.push({CU[dir].X, CU[dir].Y});
			}
		}
	}

	return false;
}

int main(void)
{
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		cin >> n;
		memset(vis, 0, sizeof(vis));

		cin >> sx >> sy;

		for(int j = 0; j < n; j++)
		{
			cin >> CU[j].X >> CU[j].Y;
		}

		cin >> ex >> ey;

		if(BFS())
		{
			cout << "happy\n";
		}
		else
		{
			cout << "sad\n";
		}
	}

	return 0;
}