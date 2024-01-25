#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	string input; cin >> input;
	string tmp;
	istringstream iss(input);

	vector<int> kda;

	while(getline(iss, tmp, '/'))
	{
		kda.push_back(stoi(tmp));
	}

	if(kda[0] + kda[2] < kda[1] || kda[1] == 0)
	{
		cout << "hasu";
	}
	else
	{
		cout << "gosu";
	}
	
	return 0;
}