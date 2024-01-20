#include<bits/stdc++.h>

using namespace std;

int n, m, p;
vector<int> lines[1001];
int deg[1001];

void topology()
{
	queue<int> q;
	vector<int> ans;

	for(int i = 1; i <= n; i++)
	{
		if(deg[i] == 0)
		{
			q.push(i);
		}
	}

	while(!q.empty())
	{
		int cur = q.front(); q.pop();

		ans.push_back(cur);

		for(int nxt : lines[cur])
		{
			deg[nxt]--;
			if(deg[nxt] == 0)
			{
				q.push(nxt);
			}
		}
	}

	if(ans.size() != n)
	{
		cout << 0 << "\n";
	}
	else
	{
		for(int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << "\n";
		}
	}
}

int main(void)
{
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		cin >> p;
		vector<int> arr;
		for(int j = 0; j < p; j++)
		{
			int x; cin >> x;
			arr.push_back(x);
		}

		for(int j = 0; j < p - 1; j++)
		{
			lines[arr[j]].push_back(arr[j+1]);
			deg[arr[j+1]]++;
		}
	}

	topology();

	return 0;
}