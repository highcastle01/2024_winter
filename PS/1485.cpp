#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;

	while(t--)
	{
		long long x[4], y[4], ans[6];
		int k = 0;

		for(int i = 0; i < 4; i++)
		{
			cin >> x[i] >> y[i];
		}

		for(int i = 0; i < 4; i++)
		{
			for(int j = i+1; j < 4; j++)
			{
				ans[k] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i]- y[j]);
				k++;
			}
		}

		sort(ans, ans + 6);

		cout << (ans[0] == ans[1] && ans[1] == ans[2] && ans[2] == ans[3] && ans[4] == ans[5]) << "\n";
	}

	return 0;
}