#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int n; cin >> n;
	int cnt = 0;
	int cur = -1;
	stack<int> st;
	bool turn = false;

	while(n--)
	{
		int x; cin >> x;
		if(st.empty())
		{
			if(x == 0)
			{
				st.push(x);
				cnt++;
				cur = 0;
			}
		}
		else
		{
			if(turn)
			{
				if(x == 0)
				{
					st.push(x);
					cnt++;
					cur++;
					turn = false;
				}
			}
			else
			{
				if(x == st.top() + 1)
				{
					st.push(x);
					cnt++;
					cur++;
					if(x == 2)
					{
						turn = true;
					}
				}
			}
		}
	}

	cout << cnt;

	return 0;
}