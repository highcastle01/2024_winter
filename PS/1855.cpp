#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int k; cin >> k;
	string str; cin >> str;
	string ans = "";
	vector<vector<string>> tmp(str.size()/k, vector<string>(k));

	int cur = 0, row = 0;

	while(cur < str.size())
	{
		if(row % 2)
		{
			for(int j = k-1; j >= 0; j--)
			{
				tmp[row][j] = str[cur];
				cur++;
			}
		}
		else
		{
			for(int j = 0; j < k; j++)
			{
				tmp[row][j] = str[cur];
				cur++;
			}
		}
		row++;
	}

	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < row; j++)
		{
			ans += tmp[j][i];
		}
	}

	cout << ans;

	return 0;
}