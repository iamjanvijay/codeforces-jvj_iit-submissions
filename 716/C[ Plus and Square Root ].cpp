#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i, N, num = 2;

	cin >> N;

	for( i=1 ; i<=N ; i++ )
	{
		cout << (i+1)*(i+1)*i - (num/i) << endl;
		num = (i+1)*i;
	}	

	return 0;
}