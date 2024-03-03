#include<bits/stdc++.h>

using namespace std;

vector<int> nlist;
vector<int> mlist;

void binarySearch(int x, int start, int end)
{
	int mid = (start + end) / 2;

	if(start > end)
	{
		cout << 0 << "\n";
		return;
	}

	if(x == nlist[mid])
	{
		cout << 1 << "\n";
		return;
	}
	else if(x > nlist[mid])
	{
		binarySearch(x, mid+1, end);
	}
	else
	{
		binarySearch(x, start, mid-1);
	}

}

int main(void)
{
	int t; cin >> t;
	
	while(t--)
	{
		int n; cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x; cin >> x;
			nlist.push_back(x);
		}
		int m; cin >> m;
		for(int i = 0; i < m; i++)
		{
			int x; cin >> x;
			mlist.push_back(x);
		}

		sort(nlist.begin(), nlist.end());

		for(int i = 0; i < m; i++)
		{
			binarySearch(mlist[i], 0, nlist.size()-1);
		}

		nlist.clear();
		mlist.clear();
	}

	return 0;
}