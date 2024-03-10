#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int ans = 0;

	while(1)
	{
		int x; cin >> x;

		if(x == -1)
		{
			break;
		}

		ans += x;
	}

	cout << ans;

	return 0;
}