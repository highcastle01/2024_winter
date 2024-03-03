#include<bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;

int main(void)
{
	int n; cin >> n;

	a.resize(n);
	b.resize(n);

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	int sum = 0;

	for(int i = 0; i < n; i++)
	{
		sum += abs(a[i] - b[i]);
	}

	cout << sum / 2;

	return 0;
}