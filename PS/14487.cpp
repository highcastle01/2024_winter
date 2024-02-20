#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	vector<int> v;
	int n; cin >> n;

	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int sum = 0;
	for(int i = 0; i < v.size() - 1; i++)
	{
		int num = v[i];
		sum += num;
	}

	cout << sum;

	return 0;
}