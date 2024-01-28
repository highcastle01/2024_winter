#include<bits/stdc++.h>

using namespace std;

int mlist[51];
int n, m, l;
int total = 0;

int left(int x)
{
	if(x > n)
	{
		x %= n;
	}

	return x;
}

int right(int x)
{
	if(x <= 0)
	{
		x += n;
	}

	return x;
}

int main(void)
{
	int x, cur = 1;
	cin >> n >> m >> l;
	mlist[cur] = 1;
	x = cur;

	while(1)
	{
		x = cur;
		for(int i = 1; i <= n; i++)
		{
			if(mlist[i] >= m)
			{
				cout << total;
				return 0;
			}
		}

		if(mlist[cur] % 2 != 0)
		{
			x += l;
			total++;
			cur = left(x);
			mlist[cur]++;
		}
		else
		{
			x -= l;
			total++;
			cur = right(x);
			mlist[cur]++;
		}
	}

	return 0;
}