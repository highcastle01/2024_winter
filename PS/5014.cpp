#include<bits/stdc++.h>

using namespace std;

int F, S, G, U, D;
bool vis[1000001];
int path[1000001];
int dx[2];

queue<int> q;

void BFS(int v)
{
	vis[v] = true;
	q.push(v);

	while(!q.empty())
	{
		v = q.front(); q.pop();

		for(int dir = 0; dir < 2; dir++)
		{
			int nxt = v + dx[dir];

			if(0 < nxt && nxt <= F)
			{
				if(!vis[nxt])
				{
					vis[nxt] = true;
					q.push(nxt);
					path[nxt] = path[v] + 1;
				}
			}
		}
	}
}

int main(void)
{
	cin >> F >> S >> G >> U >> D;
	dx[0] = U;
	dx[1] = D * -1;

	BFS(S);

	if(vis[G])
	{
		cout << path[G];
	}
	else
	{
		cout << "use the stairs";
	}

	return 0;
}

