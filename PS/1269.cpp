#include<bits/stdc++.h>

using namespace std;

vector<int> azip;
vector<int> bzip;
vector<int> abzip;
vector<int> bazip;

int main(void)
{
	int a, b; cin >> a >> b;
	int aidx = 0, bidx = 0, cnt = 0;

	for(int i = 0; i < a; i++)
	{
		int x; cin >> x;
		azip.push_back(x);
	}
	for(int i = 0; i < b; i++)
	{
		int x; cin >> x;
		bzip.push_back(x);
	}

	sort(azip.begin(), azip.end());
	sort(bzip.begin(), bzip.end());

	//정렬이 되어 있으니까 가능함.
	while(aidx < a && bidx < b)
	{
		if(azip[aidx] < bzip[bidx])
		{
			aidx++;
			cnt++;
		}
		else if(azip[aidx] > bzip[bidx])
		{
			bidx++;
			cnt++;
		}
		else
		{
			aidx++;
			bidx++;
		}
	}

	cnt += (b - bidx) + (a - aidx);

	cout << cnt;

	return 0;
}