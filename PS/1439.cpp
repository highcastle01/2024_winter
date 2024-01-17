#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int ans = 0;
	string s; cin >> s;

	vector<bool> sb;

	for(auto c : s)
	{
		if(c == '0')
		{
			sb.push_back(0);
		}
		else if(c == '1')
		{
			sb.push_back(1);
		}
	}

	bool change1 = false;
	int cnt1 = 0, cnt2 = 0;

	for(int i = 1; i < sb.size(); i++)
	{
		if(sb[i-1] != sb[i])
		{
			if(change1)
			{
				change1 = false;
			}
			else
			{
				change1 = true;
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}