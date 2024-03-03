#include<bits/stdc++.h>

using namespace std;

vector<int> board[100001];
int ans[100001];
bool vis[100001];
int n, m, r;
int cur = 0;

void DFS(int x)
{
	if(vis[x])
	{
		return;
	}

	vis[x] = true;
	cur++;
	ans[x] = cur;

	for(int i = 0; i < board[x].size(); i++)
	{
		DFS(board[x][i]);
	}
}

int main(void)
{
	cin >> n >> m >> r;

	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;

		board[u].push_back(v);
		board[v].push_back(u);
	}

	for(int i = 1; i <= n; i++)
	{
		sort(board[i].begin(), board[i].end());
	}

	DFS(r);

	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}