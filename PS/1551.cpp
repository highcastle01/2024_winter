#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<int> A;
vector<int> B;

void makes()
{
	B.resize(A.size() - 1);
	for(int i = 0; i < A.size() - 1; i++)
	{
		B[i] = A[i+1] - A[i];
	}
	A.assign(B.begin(), B.end());
}

int main(void)
{
	cin >> n >> k;
	string str; cin >> str;
	istringstream iss(str);
	string tmp;

	while(getline(iss, tmp, ','))
	{
		A.push_back(stoi(tmp));
	}

	int cnt = 0;

	if(k == 0)
	{
		B.assign(A.begin(), A.end());
	}

	while(cnt < k)
	{
		makes();
		cnt++;
	}

	for(int i = 0; i < B.size(); i++)
	{
		cout << B[i] << (i < B.size() - 1 ? "," : "");
	}

	return 0;
}