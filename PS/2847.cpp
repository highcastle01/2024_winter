#include<bits/stdc++.h>

using namespace std;

int levels[101];

int main(void)
{
	int n; cin >> n;
	int ans = 0;

	for(int i = 1; i <= n; i++)
	{
		cin >> levels[i];
	}

	for(int i = n; i > 1; i--)
	{
		if(levels[i] <= levels[i-1])
		{
			ans += levels[i-1] - levels[i] + 1;
			levels[i-1] -= levels[i-1] - levels[i] + 1;
		}
	}

	cout << ans;

	return 0;
}