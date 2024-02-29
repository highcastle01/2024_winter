#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int l, p, v, i = 1;
	while(cin >> l >> p >> v)
	{
		if(l == 0 && p == 0 && v == 0) 
		{
            break;
        }
		int turns = v / p;
		int etc = v % p;

		int ans = turns * l;
		ans += (l > etc) ? etc : l;

		cout << "Case " << i << ": " << ans << "\n";
		i++;
	}
	return 0;
}