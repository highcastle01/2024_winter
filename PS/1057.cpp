#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, a, b; cin >> n >> a >> b;

	int ans = 0;

	while(a != b)
	{
		a -= a/2;
		b -= b/2;
		ans += 1;
	}

	cout << ans;

	return 0;
}