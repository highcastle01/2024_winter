#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int n = 5;
	int i = 1;
	bool flag = false;
	while(n--)
	{
		string str; cin >> str;

		if(str.find("FBI") != string::npos)
		{
			cout << i << " ";
			flag = true;
		}
		i++;
	}

	if(!flag)
	{
		cout << "HE GOT AWAY!";
	}

	return 0;
}