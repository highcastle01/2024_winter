#include<bits/stdc++.h>

using namespace std;

int n, q;

vector<int> score;

int main(void)
{
	cin >> n >> q;

	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		for(int k = 0; k < x; k++)
		{
			score.push_back(i);
		}
	}
	for(int j = 0; j < q; j++)
	{
		int x; cin >> x;
		cout << score[x] << "\n";
	}


	return 0;
}