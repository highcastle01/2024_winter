#include<bits/stdc++.h>

using namespace std;

vector<int> lines[32001];
int deg[32001];

int n, m;

void topology()
{
    queue<int> q;

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

        cout << cur << " ";

        for(int nxt : lines[cur])
        {
            deg[nxt]--;
            if(deg[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }
}

void topology2()
{
    queue<int> q;

    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 0)
        {
            q.push(i);
        }
    }

    for(int i = 0; i < n; i++)
    {
        int cur = q.front(); q.pop();

        cout << cur << " ";

        for(int nxt : lines[cur])
        {
            deg[nxt]--;
            if(deg[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }
}

int main(void)
{
    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        int a, b; cin >> a >> b;

        lines[a].push_back(b);
        deg[b]++;
    }

    topology2();

    return 0;
}
