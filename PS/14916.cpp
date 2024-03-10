#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int n; cin >> n;
	int ans = 0;

	if(n % 5 == 0)
	{
		cout << n / 5;
	}
	else
	{
		while(n > 0)
		{
			n -= 2;
			ans++;
			if(n % 5 == 0)
			{
				cout << ans + n/5;
				break;
			}
		}
	}

	if(n < 0)
	{
		cout << -1;
	}

	return 0;
}