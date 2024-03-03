#include<bits/stdc++.h>

using namespace std;

int n, cnt = 0;
map<string, int> words;
map<string, int>:: iterator it;

void makeWords(int i, string str)
{
	for(int j = 0; j < str.size(); j++)
	{
		string tmp = "";
		for(int k = j; k < str.size(); k++)
		{
			tmp = tmp + str[k];
		}

		for(int l = 0; l < j; l++)
		{
			tmp = tmp + str[l];
		}

		words.insert({tmp, i});
	}
}

int main(void)
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		string str; cin >> str;
		it = words.find(str);

		if(it == words.end())
		{
			cnt++;
			makeWords(i, str);
		}
	}

	cout << cnt;

	return 0;
}