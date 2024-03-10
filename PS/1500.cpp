#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	long long s, k; cin >> s >> k;

	long long p = (s/k), q = (s%k);
	long long ans = 1;

	for(int i = 0; i < k; i++)
	{
		if(q > 0)
		{
			ans *= p+1;
			q--;
		}
		else
		{
			ans *= p;
		}
	}

	cout << ans;

	return 0;
}