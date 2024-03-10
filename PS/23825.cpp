#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, m; cin >> n >> m;
	int ans = ((n/2) > (m/2)) ? m/2 : n/2;

	cout << ans;
	
	return 0;
}